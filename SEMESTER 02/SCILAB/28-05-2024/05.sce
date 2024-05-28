clc;
clear;
//clf;

A = [1, 0, 0; 0, 1, 0; 0, 0, 1];

eval = spec(A);
disp(eval);

[evec, diagonal_matrix] = spec(A);
disp(evec);
disp(diagonal_matrix);
