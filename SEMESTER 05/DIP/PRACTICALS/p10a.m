clc;
clear;
close all;

img = imread('sample/pout.tif');

if size(img, 3) == 3
    img = rgb2gray(img);
end

[rows, cols] = size(img);
total_pixels = rows * cols;
L = 256;

img_flat = img(:);
img_equalized_flat = zeros(total_pixels, 1, 'uint8');

% 1. Calculate histogram
hist_counts = imhist(img);

% 2. Calculate PDF
pdf = hist_counts / total_pixels;

% 3. Calculate CDF
cdf = cumsum(pdf);

% 4. Map CDF to new gray levels [0-255]
cdf_scaled = round(cdf * (L - 1));

% 5. Create new image by mapping old values to new
for i = 1:total_pixels
    original_value = img_flat(i);
    img_equalized_flat(i) = cdf_scaled(original_value + 1);
end

img_equalized = reshape(img_equalized_flat, rows, cols);

figure;
subplot(2, 2, 1);
imshow(img);
title('Original Image');

subplot(2, 2, 2);
imhist(img);
title('Original Histogram');

subplot(2, 2, 3);
imshow(img_equalized);
title('Equalized Image (Manual)');

subplot(2, 2, 4);
imhist(img_equalized);
title('Equalized Histogram');