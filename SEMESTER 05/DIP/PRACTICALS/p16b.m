clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

% 1. Convert to Grayscale
if size(img, 3) == 3
    img_gray = rgb2gray(img);
else
    img_gray = img;
end

% 2. Smoothing (Gaussian Blur)
sigma = 2;
img_blurred = imgaussfilt(img_gray, sigma);

% 3. Edge Detection (Canny)
img_edges = edge(img_blurred, 'Canny');

figure;
subplot(2, 2, 1);
imshow(img);
title('Original Image');

subplot(2, 2, 2);
imshow(img_gray);
title('Grayscale Image');

subplot(2, 2, 3);
imshow(img_blurred);
title('Gaussian Blurred Image');

subplot(2, 2, 4);
imshow(img_edges);
title('Canny Edges');