clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');
if size(img, 3) == 3
    img = rgb2gray(img);
end

[rows, cols] = size(img);
bitSlices = zeros(rows, cols, 8, 'uint8');

for bit = 1:8
    mask = bitshift(1, bit - 1);
    bitPlane = bitand(img, mask);
    bitSlices(:, :, bit) = bitPlane * 255;
end

figure;
subplot(3, 3, 1);
imshow(img);
title('Original Image');

for bit = 1:8
    subplot(3, 3, bit + 1);
    imshow(bitSlices(:, :, bit));
    title(['Bit Plane ' num2str(bit)]);
end