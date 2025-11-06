clc;
clear;
close all;

img_rgb = imread('sample/badminton.jpg');

img_gray = rgb2gray(img_rgb);

figure;
subplot(1, 2, 1);
imshow(img_rgb);
title('Original RGB Image');

subplot(1, 2, 2);
imshow(img_gray);
title('Grayscale Image');