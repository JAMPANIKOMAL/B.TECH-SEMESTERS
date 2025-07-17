clc;
clear;
close all;

x = imread('sample/badminton.jpg');
[h, w, ch] = size(x);

fprintf("Height is %d\n", h);
fprintf("Width is %d\n", w);
fprintf("No of channels is %d\n", ch);

figure;
imshow(x);
title('Badminton RGB');