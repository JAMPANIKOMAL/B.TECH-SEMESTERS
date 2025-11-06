clc;
clear;
close all;

cover_img = imread('sample/cameraman.jpeg');
watermark_img = imread('sample/tire.tif');

if size(cover_img, 3) == 3
    cover_img = rgb2gray(cover_img);
end

if size(watermark_img, 3) == 3
    watermark_img = rgb2gray(watermark_img);
end

watermark_resized = imresize(watermark_img, size(cover_img));
watermark_binary = imbinarize(watermark_resized);

watermarked_lsb = bitset(cover_img, 1, logical(watermark_binary));
watermarked_7th = bitset(cover_img, 7, logical(watermark_binary));

figure;
subplot(2, 2, 1);
imshow(cover_img);
title('Cover Image (Cameraman)');

subplot(2, 2, 2);
imshow(watermark_binary);
title('Watermark (Tire)');

subplot(2, 2, 3);
imshow(watermarked_lsb);
title('Watermarked at LSB (Bit 1)');

subplot(2, 2, 4);
imshow(watermarked_7th);
title('Watermarked at Bit 7');