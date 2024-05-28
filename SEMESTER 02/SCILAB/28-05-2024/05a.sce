clc;
clear;

A = [1, 2, 3; 4, 5, 6; 7, 8, 9];
disp(rank(A));

disp(kernel(A));
disp(size(kernel(A), 2));
