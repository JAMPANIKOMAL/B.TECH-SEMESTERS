% Aim: Histogram equilisation without using built-in function like

clc;
clear;
close all;

i = imread("sample/foosball.png");

% Convert the image to grayscale if it is not already
if size(i, 3) == 3
    i = rgb2gray(i);
end

% Get the histogram of the image
[counts, ~] = imhist(i);
numPixels = sum(counts);
pdf = counts / numPixels; % Probability density function

% Compute the cumulative distribution function (CDF)
cdf = cumsum(pdf);

% Normalize the CDF
cdf = cdf * 255; % Scale to the range [0, 255]

% Map the old pixel values to the new pixel values
equalizedImage = uint8(zeros(size(i)));
for pixelValue = 0:255
    equalizedImage(i == pixelValue) = cdf(pixelValue + 1);
end

% Display the original and equalized images
figure;
subplot(2,2,1);
imshow(i);
title('Original Image');

subplot(2,2,2);
imhist(i);
title('Original Histogram');

subplot(2,2,3);
imshow(equalizedImage);
title('Equalized Image');

subplot(2,2,4);
imhist(equalizedImage);
title('Equalized Histogram');