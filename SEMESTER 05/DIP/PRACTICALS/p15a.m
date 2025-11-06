clc;
clear;
close all;

img = imread('sample/car.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

img_binary = imbinarize(img);

se_3 = strel('disk', 3);
se_5 = strel('disk', 5);
se_7 = strel('disk', 7);

img_eroded_3 = imerode(img_binary, se_3);
img_eroded_5 = imerode(img_binary, se_5);
img_eroded_7 = imerode(img_binary, se_7);

figure;
subplot(1, 4, 1);
imshow(img_binary);
title('Original Binary');

subplot(1, 4, 2);
imshow(img_eroded_3);
title('Erosion (SE=3)');

subplot(1, 4, 3);
imshow(img_eroded_5);
title('Erosion (SE=5)');

subplot(1, 4, 4);
imshow(img_eroded_7);
title('Erosion (SE=7)');