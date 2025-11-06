clc;
clear;
close all;

img_rgb = imread('sample/badminton.jpg');

img_gray = rgb2gray(img_rgb);
img_bw = imbinarize(img_gray);
img_ycbcr = rgb2ycbcr(img_rgb);
img_hsv = rgb2hsv(img_rgb);
img_cmy = imcomplement(im2double(img_rgb));

figure;

subplot(2, 3, 1);
imshow(img_rgb);
title('RGB (Original)');

subplot(2, 3, 2);
imshow(img_gray);
title('Grayscale');

subplot(2, 3, 3);
imshow(img_bw);
title('Black & White');

subplot(2, 3, 4);
imshow(img_ycbcr);
title('YCbCr');

subplot(2, 3, 5);
imshow(img_hsv);
title('HSV');

subplot(2, 3, 6);
imshow(img_cmy);
title('CMY');