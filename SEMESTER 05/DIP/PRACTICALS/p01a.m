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
disp(img);

id = im2double(img);
disp(id);
r = 60;
c = 105;
intensity = id(r, c);

fprintf("Pixel value at row position %d, col position %d is %.4f\n", r, c, intensity);