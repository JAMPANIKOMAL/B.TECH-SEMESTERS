clc;
clear;
close all;

img = imread('sample/pout.tif');

if size(img, 3) == 3
    img = rgb2gray(img);
end

img_double = double(img);

c = 1;
log_transformed = c * log(1 + img_double);

log_display = mat2gray(log_transformed);

figure;
subplot(1, 2, 1);
imshow(img);
title('Original Image');

subplot(1, 2, 2);
imshow(log_display);
title('Logarithmic Transformed Image');