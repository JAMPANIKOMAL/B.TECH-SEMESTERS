% Aim:
% 10c
% To perform convolution and correlation operation on 1d and 2d arrays

clc;
clear;
close all;

% Define 1D arrays for convolution and correlation
x1 = [1, 2, 3, 4, 5];
h1 = [0.2, 0.5, 0.3];

% Perform convolution on 1D arrays
conv_1d = conv(x1, h1);

% Perform correlation on 1D arrays
corr_1d = xcorr(x1, h1);

% Display results
disp('1D Convolution Result:');
disp(conv_1d);
disp('1D Correlation Result:');
disp(corr_1d);

% Define 2D arrays for convolution and correlation
A = [1, 2, 3; 4, 5, 6; 7, 8, 9];
B = [1, 0; 0, -1];

% Perform convolution on 2D arrays
conv_2d = conv2(A, B, 'full');

% Perform correlation on 2D arrays
corr_2d = xcorr2(A, B);

% Display results
disp('2D Convolution Result:');
disp(conv_2d);
disp('2D Correlation Result:');
disp(corr_2d);