clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');
img_double = im2double(img);

I_noisy1 = imnoise(img_double, 'gaussian', 0, 0.02);
I_noisy2 = imnoise(img_double, 'gaussian', 0, 0.05);

h3 = fspecial('average', [3 3]);
h5 = fspecial('average', [5 5]);

I_noisy1_3 = imfilter(I_noisy1, h3, 'replicate');
I_noisy1_5 = imfilter(I_noisy1, h5, 'replicate');

I_noisy2_3 = imfilter(I_noisy2, h3, 'replicate');
I_noisy2_5 = imfilter(I_noisy2, h5, 'replicate');

figure;
subplot(3, 3, 1); imshow(img); title('Original Image');
subplot(3, 3, 2); imshow(I_noisy1); title('Gaussian Noise (var=0.02)');
subplot(3, 3, 3); imshow(I_noisy1_3); title('var=0.02, 3x3 Box Filter');
subplot(3, 3, 4); imshow(I_noisy1_5); title('var=0.02, 5x5 Box Filter');
subplot(3, 3, 5); imshow(I_noisy2); title('Gaussian Noise (var=0.05)');
subplot(3, 3, 6); imshow(I_noisy2_3); title('var=0.05, 3x3 Box Filter');
subplot(3, 3, 7); imshow(I_noisy2_5); title('var=0.05, 5x5 Box Filter');