clc;
clear;
close all;

i = imread("sample/cameraman.jpeg");
figure;
subplot(1,2,1);
imshow(i);
title("Original Image");
subplot(1,2,2);
imhist(rgb2gray(i)); % Convert to grayscale if the image is not already
title("Histogram");