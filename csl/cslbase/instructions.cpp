//
//instructions.cpp
//
//Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
//This library is licensed under the BSD license. See the file COPYING.
//

// $Id$

#include "instructions.h"

#include "insts.h"
#include "prefix.h"
#include "textdefs.h"
#include "x86defs.h"
#include "wstring.h"

// I use the trie data structure as I found it most fitting to a disassembler mechanism.
// When you read a byte and have to decide if it's enough or you should read more bytes, 'till you get to the instruction information.
// It's really fast because you POP the instruction info in top 3 iterates on the DB, because an instruction can be formed from two bytes + 3 bits reg from the ModR/M byte.
// For a simple explanation, check this out:
// http://www.csse.monash.edu.au/~lloyd/tildeAlgDS/Tree/Trie/
// Futher reading: http://en.wikipedia.org/wiki/Trie

//
//
//The first GATE (array you read from in a trie data structure), as I call them, is statically allocated by the compiler.
//The second and third gates if used are being allocated dynamically by the instructions-insertion functionality.
//
//How would such a thing look in memory, say we support 4 instructions with 3 bytes top (means 2 dynamically allocated gates).
//
//->
//|-------|                                0,
//|0|     -------------------------------> |-------|
//|1|RET  |      1,                        |0|AND  |
//|2|     -----> |-------|                 |1|XOR  |
//|3|INT3 |      |0|PUSH |                 |2|OR   |         0,3,
//|-------|      |1|POP  |                 |3|     --------->|-------|
//             |2|PUSHF|                 |-------|         |0|ROR  |
//             |3|POPF |                                   |1|ROL  |
//             |-------|                                   |2|SHR  |
//                                                         |3|SHL  |
//                                                         |-------|
//
//Of course, this is NOT how Intel instructions set looks!!!
//but I just wanted to give a small demonstration.
//Now the instructions you get from such a trie DB goes like this:
//
//0, 0 - AND
//0, 1 - XOR
//0, 2 - OR
//0, 3, 0, ROR
//0, 3, 1, ROL
//0, 3, 2, SHR
//0, 3, 3, SHL
//1 - RET
//2, 0 - PUSH
//2, 1 - POP
//2, 2 - PUSHF
//2, 3 - POPF
//3 - INT3
//
//I guess it's clear by now.
//So now, if you read 0, you know that you have to enter the second gate(list) with the second byte specifying the index.
//But if you read 1, you know that you go to an instruction (in this case, a RET).
//That's why there's an Instruction-Node structure, it tells you whether you got to an instruction or another list
//so you should keep on reading byte).
//
//In Intel, you could go through 3 gates at top, because there're instructions which are built from 2 bytes and another smaller list
//for the REG part.
//Therefore, Intel's first gate is 256 long, and other gates are 256 or 8 long, yes, it costs pretty much alot of memory
//for non-used defined instructions, but I think that it still rocks.
//

// This function is reponsible to return the instruction information of the first found in code.
// It returns the _InstInfo of the found instruction, otherwise NULL.
// code should point to the ModR/M byte upon exit (if used), or after the instruction binary code itself.
// This function is NOT decoding-type dependant, it is up to the caller to see whether the instruction is valid.
// Get the instruction info, using a Trie data structure.
// I call it "basic", because it simply locates an instruction, it doesn't care what bytes it's using, such as prefixes.
//
_InstInfo* locate_basic_inst(const unsigned char** code0, long* codeLen0, _OffsetType* codeOffset0, _WString* instructionHex, int isERXPrefixValid, _DecodeType dt)
{   const unsigned char* code = *code0;
    long codeLen = *codeLen0;
    _OffsetType codeOffset = *codeOffset0;

    unsigned char tmpIndex0 = *code, tmpIndex1 = 0, tmpIndex2 = 0;
    _InstNode *in = NULL;
    _InstInfo *ii = NULL;

    // Single byte instruction (OCST_1BYTE).
    if (Instructions[tmpIndex0].type == INT_INFO)
    {   str_hex_b(instructionHex, tmpIndex0);

        codeLen -= 1;
        if (codeLen < 0) return NULL;
        code += 1;
        codeOffset += 1;
        *code0 = code;
        *codeLen0 = codeLen;
        *codeOffset0 = codeOffset;

        // ARPL/MOVSXD share the same instruction number, and both have differenct operands and mnemonics, of course.
        // Practically, I couldn't come up with a comfortable way to merge the operands' types of ARPL/MOVSXD.
        // And since the DB can't be patched dynamically, because the DB has to be multi-threaded compliant,
        // I have no choice but to check for ARPL/MOVSXD right here - "right about now, the funk soul brother, check it out now, the funk soul brother...", fatboy slim
        if (tmpIndex0 == INST_ARPL_INDEX) return dt == Decode64Bits ? &II_movsxd : &II_arpl;

        return Instructions[tmpIndex0].ii;
    }

    // Single byte instruction + reg bits (OCST_13BYTES).
    if (Instructions[tmpIndex0].type == INT_LIST_GROUP)
    {   str_hex_b(instructionHex, tmpIndex0);

        codeLen -= 1;
        if (codeLen <= 0) return NULL;
        code += 1;
        codeOffset += 1;
        *code0 = code;
        *codeLen0 = codeLen;
        *codeOffset0 = codeOffset;
        return Instructions[tmpIndex0].list[(*code >> 3) & 7].ii;
    }

    // Single byte instruction + reg byte OR one whole byte (OCST_1dBYTES).
    if (Instructions[tmpIndex0].type == INT_LIST_DIVIDED)
    {   str_hex_b(instructionHex, tmpIndex0);

        codeLen -= 1;
        if (codeLen <= 0) return NULL;
        code += 1;
        codeOffset += 1;

        tmpIndex1 = *code;

        if (tmpIndex1 < INST_DIVIDED_MODRM)
        {   // An instruction which requires a ModR/M byte. Thus it's 1.3 bytes long instruction.
            tmpIndex1 = (tmpIndex1 >> 3) & 7; // Isolate the 3 REG/OPCODE bits.
        }
        else     // Normal 2 bytes instruction.
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen < 0) return NULL;
            code += 1;
            codeOffset += 1;

            // Divided instructions can't be in the range of 0x8-0xc0.
            // That's because 0-8 are used for 3 bits group.
            // And 0xc0-0xff are used for not-divided instruction.
            // So the inbetween range is omitted, thus saving some more place in the tables.
            tmpIndex1 -= INST_DIVIDED_MODRM - 8;
        }

        *code0 = code;
        *codeLen0 = codeLen;
        *codeOffset0 = codeOffset;
        return Instructions[tmpIndex0].list[tmpIndex1].ii;
    }

    // At least 2 bytes long instruction (might be 2.3 or 3 or 3.3 bytes long).
    if (Instructions[tmpIndex0].type == INT_LIST_FULL)
    {   str_hex_b(instructionHex, tmpIndex0);

        if (isERXPrefixValid)
        {   // Skip REX prefix byte.
            codeLen -= 1;
            if (codeLen <= 0) return NULL;
            code += 1;
            codeOffset += 1;
            str_hex_sp_b(instructionHex, *code);
            chrcat_WS(instructionHex, SP_CHR);
        }

        codeLen -= 1;
        if (codeLen <= 0) return NULL;
        code += 1;
        codeOffset += 1;

        tmpIndex1 = *code;
        in = &Instructions[tmpIndex0].list[tmpIndex1];

        // This is where we check if we just read two escape bytes in a row, which means it is a 3DNow! instruction.
        if ((tmpIndex0 == _3DNOW_ESCAPE_BYTE) && (tmpIndex1 == _3DNOW_ESCAPE_BYTE))
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen < 0) return NULL;
            code += 1;
            codeOffset += 1;

            *code0 = code;
            *codeLen0 = codeLen;
            *codeOffset0 = codeOffset;
            return &II_3dnow;
        }

        // 2 bytes instruction (OCST_2BYTES).
        if (in->type == INT_INFO)
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen < 0) return NULL;
            code += 1;
            codeOffset += 1;

            *code0 = code;
            *codeLen0 = codeLen;
            *codeOffset0 = codeOffset;
            return in->ii;
        }

        // 2 bytes + reg instruction (OCST_23BYTES).
        if (in->type == INT_LIST_GROUP)
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen <= 0) return NULL;
            code += 1;
            codeOffset += 1;

            *code0 = code;
            *codeLen0 = codeLen;
            *codeOffset0 = codeOffset;
            return in->list[(*code >> 3) & 7].ii;
        }

        // 2 bytes + divided range (OCST_2dBYTES).
        if (in->type == INT_LIST_DIVIDED)
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen <= 0) return NULL;
            code += 1;
            codeOffset += 1;

            tmpIndex2 = *code;
            ii = in->list[(tmpIndex2 >> 3) & 7].ii;

            // If the instruction wasn't divided (but still it must be a 2.3) or it was an official 2.3 (because its index was less than 0xc0)
            // Then it means the instruction should be used the REG bits, otherwise give a chance to range 0xc0-0xff.
            if ((ii != NULL) && ((ii->flags & INST_NOT_DIVIDED) || (tmpIndex2 < INST_DIVIDED_MODRM))) tmpIndex2 = (tmpIndex2 >> 3) & 7;
            else if (tmpIndex2 >= INST_DIVIDED_MODRM) tmpIndex2 -= INST_DIVIDED_MODRM - 8; // Divided tables are smaller, range 0x8-0xc0 is omitted.
            ii = in->list[tmpIndex2].ii;
            if ((ii != NULL) && ((ii->flags & INST_INCLUDE_MODRM) == 0))   // Read 3 whole bytes.
            {   str_hex_b(instructionHex, tmpIndex2);

                codeLen -= 1;
                if (codeLen < 0) return NULL;
                code += 1;
                codeOffset += 1;
            }

            *code0 = code;
            *codeLen0 = codeLen;
            *codeOffset0 = codeOffset;
            return ii;
        }

        // At least 3 bytes (OCST_3BYTES).
        if (in->type == INT_LIST_FULL)
        {   str_hex_b(instructionHex, tmpIndex1);

            codeLen -= 1;
            if (codeLen < 0) return NULL;
            code += 1;
            codeOffset += 1;

            tmpIndex2 = *code;

            // 3.3 bytes (OCST_33BYTES).
            if (in->list[tmpIndex2].type == INT_LIST_GROUP)
            {   str_hex_b(instructionHex, tmpIndex2);

                codeLen -= 1;
                if (codeLen <= 0) return NULL;
                code += 1;
                codeOffset += 1;

                *code0 = code;
                *codeLen0 = codeLen;
                *codeOffset0 = codeOffset;
                return in->list[tmpIndex2].list[(*code >> 3) & 7].ii;
            }
            else     // OCST_3BYTES.
            {   str_hex_b(instructionHex, tmpIndex2);

                codeLen -= 1;
                if (codeLen < 0) return NULL;
                code += 1;
                codeOffset += 1;

                *code0 = code;
                *codeLen0 = codeLen;
                *codeOffset0 = codeOffset;
                return in->list[tmpIndex2].ii;
            }
        }
    }

    // Kahtchinggg, damn.
    return NULL;
}

// Locate an instruction, give chance to SSE/2/3 instructions which need the prefix as a nomral byte instruction!
_InstInfo* locate_inst(const unsigned char** code,  long* codeLen, _OffsetType* codeOffset, _WString* instructionHex, _PrefixState* ps, _DecodeType dt)
{   _InstInfo* ii = NULL;

    unsigned long lastCodeLen = *codeLen;
    _OffsetType lastCodeOffset = *codeOffset;
    const unsigned char* lastCode = *code;

    unsigned char lastBC = 0; // byte code.

    // Keep last byte code, raed from ps->last only if we skipped prefixes.
    if (ps->start < ps->last)
    {   if (ps->isREXPrefixValid) lastBC = *(ps->last - 2); // Skip REX prefix byte.
        else lastBC = *(ps->last-1);
    }
    //
//  Sometimes normal prefixes become mandatory prefixes, which means they are now part of the instruction opcode bytes.
//
//  This is a bit tricky now,
//  if the first byte is a REP (F3) prefix, we will have to give a chance to an SSE instruction.
//  If an instruction doesn't exist, we will make it as a prefix and re-locateinst.
//  A case sach that a REP prefix is being changed into an instruction byte and also an SSE instruction will not be found can't happen,
//  simply because there are no collisions between string instruction and SSE instructions (they are escaped).
//
//  As for SSE2/3, check for F2 and 66 as well.
//
//  In 64 bits, we have to make sure that we will skip the REX prefix, if it exists.
//  There's a specific case, where a 66 is mandatory but it was dropped because REG.W was used,
//  but it doesn't behave as an operand size prefix but as a mandatory, so we will have to take it into account.
//
//  For example (64 bits decoding mode):
//  66 98 CBW
//  48 98 CDQE
//  66 48 98: db 0x66; CDQE
//  Shows that operand size is dropped.
//
//  Now, it's a mandatory prefix and NOT an operand size one.
//  66480f2dc0 db 0x48; CVTPD2PI XMM0, XMM0
//  Although this instruction doesn't require a REX.W, it just shows, that even if it did - it doesn't matter.
//  REX.W is dropped because it's not requried, but the decode function disabled the operand size even so.
//
    if ((lastBC == PREFIX_REP) || (lastBC == PREFIX_REPNZ) || (lastBC == PREFIX_OP_SIZE))
    {   // Take the prefix into account, making it an instruction byte.
        if (ps->isREXPrefixValid)
        {   (*code) -= 2;
            (*codeLen) += 2;
            (*codeOffset) -= 2;
        }
        else
        {   (*code)--;
            (*codeLen)++;
            (*codeOffset)--;
        }
        ii = locate_basic_inst(code, codeLen, codeOffset, instructionHex, ps->isREXPrefixValid, dt);
        if (ii)
        {   // An SSE/2/3 instruction was found,
            // so remove the last prefix. It is now a mandatory prefix and skip REX as usual.

            // Let the decode function know that we turned a prefix into mandatory one.
            // So if some problem occurs later, we will know to handle it specially because of this end case.
            if (ps->isREXPrefixValid)
            {   ps->last -= 2;
                ps->specialPrefixesSize = 2; // REX + SSE.
            }
            else
            {   ps->last--;
                ps->specialPrefixesSize = 1; // SSE only.
            }

            // Remove that flag specifically.
            switch (lastBC)
            {   case PREFIX_REP: ps->totalPrefixes &= ~INST_PRE_LOKREP_MASK; ps->lokrepPos = NULL; break;
                case PREFIX_REPNZ: ps->totalPrefixes &= ~INST_PRE_LOKREP_MASK; ps->lokrepPos = NULL; break;
                case PREFIX_OP_SIZE: ps->totalPrefixes &= ~INST_PRE_OP_SIZE; ps->opsizePos = NULL; break;
            }
        }
        else
        {   // Undo:
            strclear_WS(instructionHex); // Remove outputed prefix.
            *code = lastCode;
            *codeLen = lastCodeLen;
            *codeOffset = lastCodeOffset;
        }
    }
    // No instruction was found before, so it's a "simple" one:
    if (ii == NULL) ii = locate_basic_inst(code, codeLen, codeOffset, instructionHex, 0, dt);
    return ii;
}

//
//3DNow! instruction handling:
//
//This is used when we encounter a 3DNow! instruction.
//We can't really locate a 3DNow! instruction before we see two escaped bytes,
//0x0f, 0x0f. Then we have to extract operands which are, dest=mmx register, src=mmx register or quadword indirection.
//When we are finished with the extraction of operands we can resume to locate the instruction by reading another byte
//which tells us which 3DNow instruction we really tracked down...
//So in order to tell the extract operands function which operands the 3DNow! instruction require, we need to set up some
//generic instruction info for 3DNow! instructions.
//
//In the locate_inst itself, when we read an OCST_3BYTES which the two first bytes are 0x0f and 0x0f.
//we will return this special generic II for the specific operands we are interested in (MM, MM64).
//Then after extracting the operand, we'll call a completion routine for locating the instruction
//which will be called only for 3DNow! instructions, distinguished by a flag, and it will read the last byte of the 3 bytes.
//
_InstInfo II_3dnow = {OT_MM, OT_MM64, "_3DNow! II", INST_32BITS | INST_INCLUDE_MODRM | INST_3DNOW_FETCH | INST_3DNOW};

_InstInfo* locate_3dnow_inst(_CodeInfo* ci, _WString* instructionHex)
{   unsigned char tmpIndex2 = *ci->code;
    // Start off from the two escape bytes gates...
    _InstNode* in = &Instructions[_3DNOW_ESCAPE_BYTE].list[_3DNOW_ESCAPE_BYTE];

    if (in->list[tmpIndex2].type == INT_INFO)
    {   str_hex_sp_b(instructionHex, tmpIndex2);

        ci->codeLen -= 1;
        if (ci->codeLen < 0) return NULL;
        ci->code += 1;
        ci->codeOffset += 1;
    }
    return in->list[tmpIndex2].ii;
}

// Formats the string according to the operand type given.
//I.E: ADD [BX], 5, how do you know the size of the destination in memory, if it is a BYTE destination or a WORD destination?
//So the output for instance is: ADD *BYTE* [BX], 5
//
//We use the DT for cases that prefixes affect the decoding.
//If you decode in 16 bits then a pointer(indirection) will be to a WORD size.
//If you decode in 32 bits then a pointer will be to a DWORD size.
//The catch is that an OPERAND size prefix switches the default of these statements, I.E:
//83 17 05 in 32 bits, decoded to: ADC DWORD [EDI], +0x05.
//So if you add a 67(ADDR SIZE Prefix) it will affect the pointer itself (EDI) to be decoded as if it were decoded in 16 bits,
//in short term, affecting the INDIRECTION size.
//But how can you POINT to 16 bits if you decode in 32 bits? You use the operand size, I.E:
//66 83 17 05 in 32 bits, decoded to: ADC WORD [EDI], +0x05.
//
//It's a bit confusing, 2 guidelines to follow:
//Operand Size prefix affects the size of the value whether it's an immediate or the value in memory which is being pointed to!
//And Address Size prefix affects the decoding of the value of the pointer(indirection)!
//
//Anyways, you have to write the size explicitly when it's uncleared from reading the operands.
//
//Take in account second operand type, because if we know what is the second operand type (in case one exists),
//the prefix is useless(I.E: ADD [bx], ax).
//However, we have such cases where you need the prefix anyways(I.E: MOVZX ebx, byte [edi]), which means that you have
//to add a prefix when the destination variable size is greater than the source variable size...
//
void str_indirection_text(_WString* s, _OpType ot, _OpType ot2, _DecodeType dt, _PrefixState* ps)
{   switch (ot)
    {   case OT_MM32:
            strcat_WSN(s, TEXT_32_BITS);
            return;
        case OT_MM64:
            strcat_WSN(s, TEXT_64_BITS);
            return;
        case OT_XMM32:
            strcat_WSN(s, TEXT_32_BITS);
            return;
        case OT_XMM64:
            strcat_WSN(s, TEXT_64_BITS);
            return;
        case OT_XMM128:
            strcat_WSN(s, TEXT_128_BITS);
            return;
        case OT_FPUM16:
            strcat_WSN(s, TEXT_16_BITS);
            return;
        case OT_FPUM32:
            strcat_WSN(s, TEXT_32_BITS);
            return;
        case OT_FPUM64:
            strcat_WSN(s, TEXT_64_BITS);
            return;
        case OT_FPUM80:
            strcat_WSN(s, TEXT_80_BITS);
            return;
        case OT_R32M16:
            strcat_WSN(s, TEXT_16_BITS);
            return;
        case OT_RFULL_M16:
            // MOV OT_RFULL_M16, SREG eats operand size prefix without any effect.
            // This is because stupid assemblers insert the 0x66 prefix for this instruction anyways.
            ps->usedPrefixes |= (ps->totalPrefixes & INST_PRE_OP_SIZE);
            strcat_WSN(s, TEXT_16_BITS);
            return;
        default:
            return;
    }
    switch (ot2)
    {   // Used by MOVSX/MOVZX, in a case like: MOVZX EBP, *BYTE* [EBX].
        case OT_REG_FULL:
            // Special case - notice that the destination is 32 or 64 bits and the source is RM(!) 8.
            if (ot == OT_RM8)
            {   strcat_WSN(s, TEXT_8_BITS);
            }
            return;
        case OT_REG32_64:
            // Special case - notice that the destination is 32 or 64 bits and the source is RM(!) 8.
            if (ot == OT_RM16)
            {   strcat_WSN(s, TEXT_16_BITS);
            }
            return;
        default:
            return;
    }
    if (ot != OT_MEM1616)   // No need if it's [16:16], in a case like: BOUND EAX, [EBX].
    {   // Rolls, Shifts, Bit Operations.
        if (ot2 == OT_NONE || ot2 == OT_IMM8 || ot2 == OT_IMM_FULL || ot2 == OT_IMM32 || ot2 == OT_SEIMM8 || ot2 == OT_REGCL || ot2 == OT_CONST1)
        {   switch (ot)
            {   case OT_RM8:
                    strcat_WSN(s, TEXT_8_BITS);
                    return;
                case OT_RM_FULL:
                    ps->usedPrefixes |= (ps->totalPrefixes & INST_PRE_OP_SIZE);
                    if (dt == Decode32Bits)
                    {   strcat_WSN(s, TEXT_32_BITS);
                        return;
                    }
                    else if (dt == Decode64Bits)
                    {   ps->usedPrefixes |= INST_PRE_REX;
                        strcat_WSN(s, TEXT_64_BITS);
                        return;
                    }
                // FALL THROUGH CUZ dt==Decoded16Bits @-<----
                case OT_RM16:
                    ps->usedPrefixes |= (ps->totalPrefixes & INST_PRE_OP_SIZE);
                    strcat_WSN(s, TEXT_16_BITS);
                    return;
                case OT_RM32:
                    ps->usedPrefixes |= (ps->totalPrefixes & INST_PRE_OP_SIZE);
                    strcat_WSN(s, TEXT_32_BITS);
                    return;
                default:
                    return;
            }
        }
    }
}

// end of instructions.cpp
