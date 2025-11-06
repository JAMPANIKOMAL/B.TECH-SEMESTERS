clc;
clear;
close all;

img = imread('sample/foosball.png');

if size(img, 3) == 3
    img_gray = rgb2gray(img);
else
    img_gray = img;
end

img_histeq = histeq(img_gray);
img_adapthisteq = adapthisteq(img_gray);

figure;

subplot(3, 2, 1);
imshow(img_gray);
title('1. Original Image');

subplot(3, 2, 2);
imhist(img_gray);
title('Histogram - Original');

subplot(3, 2, 3);
imshow(img_histeq);
title('2. Standard Hist. Equalized');

subplot(3, 2, 4);
imhist(img_histeq);
title('Histogram - Standard Eq.');

subplot(3, 2, 5);
imshow(img_adapthisteq);
title('3. Adaptive Hist. Equalized');

subplot(3, 2, 6);
imhist(img_adapthisteq);
title('Histogram - Adaptive Eq.');