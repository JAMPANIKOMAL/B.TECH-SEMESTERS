clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

img_double = im2double(img);

nbits = 2;
levels = 2^nbits;
steps = 1 / levels;

bins = floor(img_double / steps);
quantized_values = (bins * steps) + (steps / 2);
quantized_img = im2uint8(quantized_values);

figure;
subplot(2, 2, 1);
imshow(img);
title('Original Image');

subplot(2, 2, 2);
imhist(img);
title('Histogram of Original');

subplot(2, 2, 3);
imshow(quantized_img);
title('Quantized Image (2-bit, 4 Levels)');

subplot(2, 2, 4);
imhist(quantized_img);
title('Histogram of Quantized');