clc;
clear;
close all;

% Note: '17A.jpg' is used in the practical file, but since it's not in the sample folder, 
% we will use the highly contrasted 'birds1.png' image, as it thresholds well.
img = imread('sample/birds1.png');

if size(img, 3) == 3
    img = rgb2gray(img);
end
                                      
% 1. Calculate the optimal threshold T using Otsu's method
T_otsu = graythresh(img);

% 2. Apply the threshold to create the binary image
img_binary = imbinarize(img, T_otsu);

figure;
subplot(1, 2, 1);
imshow(img);
title('Original Grayscale Image');

subplot(1, 2, 2);
imshow(img_binary);
title(['Binary Image (Otsu Threshold T = ', num2str(T_otsu, '%.4f'), ')']);