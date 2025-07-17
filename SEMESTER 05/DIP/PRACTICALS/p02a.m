clc;
clear;
close all;

i = imread('sample/badminton.jpg');
j = rgb2gray(i);
k = imbinarize(j);
l = rgb2ycbcr(i);
m = rgb2hsv(i);
n = 1 - im2double(i); 

figure;
subplot(2, 3, 1);
imshow(i);
title('Original RGB');

subplot(2, 3, 2);
imshow(j);
title('Gray Scale');

subplot(2, 3, 3);
imshow(k);
title('Black & White');

subplot(2, 3, 4);
imshow(l);
title('YCbCr');

subplot(2, 3, 5);
imshow(m);
title('HSV');

subplot(2, 3, 6);
imshow(n);
title('CMY');