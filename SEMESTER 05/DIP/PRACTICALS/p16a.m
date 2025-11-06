clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

se = strel('disk', 5);

img_opened = imopen(img, se);
img_closed = imclose(img, se);

figure;
subplot(1, 3, 1);
imshow(img);
title('Original Image');

subplot(1, 3, 2);
imshow(img_opened);
title('Opened Image');

subplot(1, 3, 3);
imshow(img_closed);
title('Closed Image');