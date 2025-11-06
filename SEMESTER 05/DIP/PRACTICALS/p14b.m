clc;
clear;
close all;

img = imread('sample/car.jpeg');
if size(img, 3) == 3
    img = rgb2gray(img);
end

img = double(img);

laplacian_kernel = [0 -1 0; -1 4 -1; 0 -1 0];

I_lap = imfilter(img, laplacian_kernel, 'replicate');
I_sharp = img - I_lap;

I_sharp = uint8(I_sharp);
img = uint8(img);
I_lap_display = uint8(abs(I_lap));


figure;
subplot(1, 3, 1);
imshow(img);
title('Original Image');

subplot(1, 3, 2);
imshow(I_lap_display);
title('Laplacian Edges');

subplot(1, 3, 3);
imshow(I_sharp);
title('Sharpened Image');