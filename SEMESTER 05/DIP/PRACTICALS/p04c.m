clc;
clear;
close all;

img = imread('sample/car.jpeg');

R = img(:, :, 1);
G = img(:, :, 2);
B = img(:, :, 3);

figure;
subplot(2, 2, 1);
imshow(img);
title('Original RGB Image');

subplot(2, 2, 2);
imshow(R);
title('Red Channel');

subplot(2, 2, 3);
imshow(G);
title('Green Channel');

subplot(2, 2, 4);
imshow(B);
title('Blue Channel');