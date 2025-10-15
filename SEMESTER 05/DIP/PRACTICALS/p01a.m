clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

if size(img, 3) == 3
    img = rgb2gray(img);
end

figure;
imshow(img);
title('Grayscale Image');

img_double = im2double(img);

r = 60;
c = 105;
intensity = img_double(r, c);

fprintf('Pixel value at row %d, column %d is %.4f\n', r, c, intensity);