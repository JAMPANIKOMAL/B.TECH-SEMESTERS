clc;
clear;
close all;

i = imread('sample/badminton.jpg');
j = rgb2gray(i);

figure;
subplot(1, 2, 1);
imshow(i);
title('Original RGB');

subplot(1, 2, 2);
imshow(j);
title('Gray Scale');