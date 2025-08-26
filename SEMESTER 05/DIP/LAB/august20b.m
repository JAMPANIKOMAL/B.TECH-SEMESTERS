% Aim: 11a perform image smoothing using a box filter. The box filters will be 3x3 and
% 5x5. The input image is cameraman. Salt and pepper noise will be added 
% using the imnoise function with different densities. 
% Output: noisy image 3x3 and filtered image 3x3 grid. Repeat the output with
% 5x5. The display will consist of 4 columns and 2 rows. 1st row salt and
% pepper, and 2nd row gaussian error

clc;
clear;
close all;

% Read the image
img = imread("sample/cameraman.jpeg");

% Add salt and pepper noise
noisy_img_3x3 = imnoise(img, 'salt & pepper', 0.02); % 2% noise density
noisy_img_5x5 = imnoise(img, 'salt & pepper', 0.05); % 5% noise density

% Define box filters
box_filter_3x3 = fspecial('average', [3 3]);
box_filter_5x5 = fspecial('average', [5 5]);

% Apply box filter to noisy images
filtered_img_3x3 = imfilter(noisy_img_3x3, box_filter_3x3);
filtered_img_5x5 = imfilter(noisy_img_5x5, box_filter_5x5);

% Display results
figure;
subplot(2, 4, 1), imshow(noisy_img_3x3), title('Noisy Image 3x3');
subplot(2, 4, 2), imshow(filtered_img_3x3), title('Filtered Image 3x3');
subplot(2, 4, 3), imshow(noisy_img_5x5), title('Noisy Image 5x5');
subplot(2, 4, 4), imshow(filtered_img_5x5), title('Filtered Image 5x5');
subplot(2, 4, 5), imshow(noisy_img_3x3), title('Noisy Image 3x3 (Repeat)');
subplot(2, 4, 6), imshow(filtered_img_3x3), title('Filtered Image 3x3 (Repeat)');
subplot(2, 4, 7), imshow(noisy_img_5x5), title('Noisy Image 5x5 (Repeat)');
subplot(2, 4, 8), imshow(filtered_img_5x5), title('Filtered Image 5x5 (Repeat)');
