% Aim: Bit Level Slicing

clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');

% Convert the image to grayscale if it is not already
if size(img, 3) == 3
    img = rgb2gray(img);
end

% Convert the image to double for processing
img = double(img);

% Get the number of bits in the image
numBits = 8;

% Initialize a cell array to hold the bit planes
bitPlanes = cell(1, numBits);

% Extract each bit plane
for k = 1:numBits
    bitPlanes{k} = bitand(floor(img / 2^(k-1)), 1) * 255; % Scale to 255 for display
end

% Display the original image and its bit planes
figure;
subplot(3, 3, 1);
imshow(uint8(img));
title('Original Image');

for k = 1:numBits
    subplot(3, 3, k + 1);
    imshow(uint8(bitPlanes{k}));
    title(['Bit Plane ', num2str(k)]);
end