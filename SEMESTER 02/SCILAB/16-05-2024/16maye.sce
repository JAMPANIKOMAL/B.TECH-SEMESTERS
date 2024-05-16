clc;
clear;

A = [2 1 1; 2 -1 0; 1 1 1]
//X = [x1; x2; x3]
B = [4; 3; 1]

X = inv(A)*B
disp(X)

X = inv(A')*B
disp(X)
