% Matlab program to perform image negative transformation.

clc;
clear;
close all;

i = imread("sample/cameraman.jpeg");

% Convert the image to double for processing
i_double = im2double(i);

% Perform negative transformation
negative_image = 1 - i_double;

% Convert back to uint8 for display
negative_image_uint8 = im2uint8(negative_image);

% Display the original and negative images
figure;
subplot(1, 2, 1);
imshow(i);
title('Original Image');

subplot(1, 2, 2);
imshow(negative_image_uint8);
title('Negative Image');