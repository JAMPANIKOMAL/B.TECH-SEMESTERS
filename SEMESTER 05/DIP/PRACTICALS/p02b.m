clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

figure;

subplot(1, 2, 1);
imshow(img);
title('Original Grayscale Image');

subplot(1, 2, 2);
imhist(img);
title('Histogram');