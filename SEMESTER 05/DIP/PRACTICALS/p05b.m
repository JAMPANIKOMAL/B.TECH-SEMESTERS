clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');
img = im2double(img);

[rows, cols, ~] = size(img);

crop_h = floor(rows / 2);
crop_w = floor(cols / 2);

top_right = img(1:crop_h, crop_w+1:end, :);
bottom_left = img(crop_h+1:end, 1:crop_w, :);
center = img(floor(rows/4):floor(3*rows/4), floor(cols/4):floor(3*cols/4), :);

figure;
subplot(2, 2, 1);
imshow(img);
title('Original Image');

subplot(2, 2, 2);
imshow(top_right);
title('Top-Right Crop');

subplot(2, 2, 3);
imshow(bottom_left);
title('Bottom-Left Crop');

subplot(2, 2, 4);
imshow(center);
title('Center Crop');