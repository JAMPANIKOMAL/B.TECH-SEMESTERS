clc;
clear;
close all;

img = imread('sample/birds1.png');

rot_30 = imrotate(img, 30);
rot_60 = imrotate(img, 60);
rot_90 = imrotate(img, 90);

figure;
subplot(2, 2, 1);
imshow(img);
title('Original Image');

subplot(2, 2, 2);
imshow(rot_30);
title('30 Degree Rotation');

subplot(2, 2, 3);
imshow(rot_60);
title('60 Degree Rotation');

subplot(2, 2, 4);
imshow(rot_90);
title('90 Degree Rotation');