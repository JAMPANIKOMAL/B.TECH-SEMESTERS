% write a matlab program to perform lsb watermarking
% input image: cameraman
% watermark tire image 3rd bit/7th bit add water mark
% hint: bitset

clc;
clear;
close all;

% Read the cover image and watermark image
cover = imread('sample/cameraman.jpeg');   % Grayscale cover image
watermark = imread('sample/tire.tif');     % Grayscale binary watermark

% Convert to grayscale if RGB
if size(cover, 3) == 3
    cover = rgb2gray(cover);
end
if size(watermark, 3) == 3
    watermark = rgb2gray(watermark);
end

% Resize watermark to match cover image
watermark = imresize(watermark, size(cover));

% Convert watermark to binary (0 or 1)
watermark_binary = imbinarize(watermark);

% ---- 3rd BIT WATERMARKING ----
watermarked_3rd = bitset(cover, 3, watermark_binary);

% ---- 7th BIT WATERMARKING ----
watermarked_7th = bitset(cover, 7, watermark_binary);

% ---- Display Results ----
figure('Name','LSB Watermarking','NumberTitle','off');
subplot(2,2,1); imshow(cover); title('Original Cover Image');
subplot(2,2,2); imshow(watermark_binary); title('Binary Watermark (Tire)');
subplot(2,2,3); imshow(watermarked_3rd); title('Watermarked @ 3rd Bit');
subplot(2,2,4); imshow(watermarked_7th); title('Watermarked @ 7th Bit');