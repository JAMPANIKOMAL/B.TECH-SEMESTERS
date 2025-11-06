clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');
if size(img, 3) == 3
    img = rgb2gray(img);
end

I_noisy = imnoise(img, 'gaussian', 0, 0.01);

w = [1 2 1; 2 4 2; 1 2 1];
w = w / sum(w(:));

I_smooth = imfilter(I_noisy, w, 'replicate');

figure;
subplot(1, 3, 1);
imshow(img);
title('Original Image');

subplot(1, 3, 2);
imshow(I_noisy);
title('Gaussian Noise');

subplot(1, 3, 3);
imshow(I_smooth);
title('Weighted Average Smoothing');