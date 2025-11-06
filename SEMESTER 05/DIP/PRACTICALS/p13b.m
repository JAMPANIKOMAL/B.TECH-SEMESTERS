clc;
clear;
close all;

img = imread('sample/pout.tif');
if size(img, 3) == 3
    img = rgb2gray(img);
end
                                      
I_noisy = imnoise(img, 'salt & pepper', 0.05);
I_max = ordfilt2(I_noisy, 9, ones(3,3));

figure;
subplot(1, 3, 1);
imshow(img);
title('Original Image');

subplot(1, 3, 2);
imshow(I_noisy);
title('Salt & Pepper Noise');

subplot(1, 3, 3);
imshow(I_max);
title('Maximum Filtered Image');