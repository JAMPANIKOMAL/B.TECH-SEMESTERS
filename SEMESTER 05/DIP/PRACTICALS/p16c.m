clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

noisy_img = imnoise(img, 'gaussian', 0, 0.01);

edges_original = edge(img, 'Canny');
edges_noisy = edge(noisy_img, 'Canny');

figure;
subplot(1, 3, 1);
imshow(img);
title('Original Image');

subplot(1, 3, 2);
imshow(noisy_img);
title('Image with Gaussian Noise');

subplot(1, 3, 3);
imshow(edges_noisy);
title('Edges from Noisy Image');