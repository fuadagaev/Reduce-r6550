
% Bug #116: loading the defint package fails when combinelogs is on.

on combinelogs;

int(x,x,0,1);

% However, the bug can be triggered without defint, by trying to define the following rules

operator f,g;

let { f ((e^(~y)-1)/(2*e^~x),~var) => g (x)  };

let { f ((e^(~x)-1)/(2*e^~x),~var) => g (x)  };

let { f ((e^(~y)-1)/(2*e^2),~var) => g (x)  };

let { f ((e^2-1)/(2*e^~x),~var) => g (x)  };

end;

