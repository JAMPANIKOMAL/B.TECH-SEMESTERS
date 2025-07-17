clc;
clear;
close all;

i = imread('sample/cameraman.jpeg');
ad = im2double(i);
nbits = 2;
levels = 2^nbits;
steps = 1/levels;
bins = floor(ad/steps);
qv = (bins * steps) + (steps / 2);
qvimg = im2uint8(qv);

subplot(2, 2, 1);
imshow(i);
title('Original Image');

subplot(2, 2, 2);
imhist(i);
title('Histogram of Original');

subplot(2, 2, 3);
imshow(qvimg);
title('Quantized Image');

subplot(2, 2, 4);
imhist(qvimg);
title('Histogram of Quantized Image');