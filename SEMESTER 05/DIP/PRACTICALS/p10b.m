clc;
clear;
close all;

A = [1 2 3];
B = [4 0 8];

% Euclidean distance
d_euclid = sqrt(sum((A - B).^2));

% Cityblock (Manhattan) distance
d_cityblock = sum(abs(A - B));

% Chessboard (Chebyshev) distance
d_chessboard = max(abs(A - B));

disp(['Euclidean Distance: ' num2str(d_euclid)]);
disp(['Cityblock Distance: ' num2str(d_cityblock)]);
disp(['Chessboard Distance: ' num2str(d_chessboard)]);