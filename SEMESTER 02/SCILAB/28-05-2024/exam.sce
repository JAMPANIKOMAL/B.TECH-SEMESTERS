//Using Scilab code, check whether x1 = [1, 2, 3]], x2 = [3, -2, 1], x3 = [1, -6, -5] are Linearly dependent or linearly independent.

clc;
clear;

x1 = [1, 2, 3];
x2 = [3, -2, 1];
x3 = [1, -6, -5];
disp(x1);
disp(x2);
disp(x3);

m = [x1; x2; x3];
disp(m);

rank_m = rank(m);

if (rank == 3)
    disp('Given vectors are Linearly Independent!);
else
    disp('Given vectors are Linearly dependent!);
end

