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

img_dilated_3 = imdilate(img_binary, se_3);
img_dilated_5 = imdilate(img_binary, se_5);
img_dilated_7 = imdilate(img_binary, se_7);

figure;
subplot(1, 4, 1);
imshow(img_binary);
title('Original Binary');

subplot(1, 4, 2);
imshow(img_dilated_3);
title('Dilation (SE=3)');

subplot(1, 4, 3);
imshow(img_dilated_5);
title('Dilation (SE=5)');

subplot(1, 4, 4);
imshow(img_dilated_7);
title('Dilation (SE=7)');