clc;
clear;

function [A, P] = circle(r)
    A = %pi * r * r;
    P = 2 * %pi * r;
endfunction

r = 1;
[A, P] = circle(r);
disp(A, P);

a = 3;
if(a > 3)
    disp(3);
elseif(a == 3)
        disp(3)
else
    disp(4);
end

for (i = 1:2:10)
    disp(i);
end
