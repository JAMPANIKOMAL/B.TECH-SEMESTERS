clc;
clear;
close all;

% --- 1D Operations ---

x1 = [1, 2, 3, 4, 5];
h1 = [0.2, 0.5, 0.3];

conv_1d = conv(x1, h1);
corr_1d = xcorr(x1, h1);

disp('1D Convolution Result:');
disp(conv_1d);

disp('1D Correlation Result:');
disp(corr_1d);


% --- 2D Operations ---

A = [1, 2, 3; 4, 5, 6; 7, 8, 9];
B = [1, 0; 0, -1];

conv_2d = conv2(A, B);
corr_2d = xcorr2(A, B);

disp('2D Convolution Result:');
disp(conv_2d);

disp('2D Correlation Result:');
disp(corr_2d);