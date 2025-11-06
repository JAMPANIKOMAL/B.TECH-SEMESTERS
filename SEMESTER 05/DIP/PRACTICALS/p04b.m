clc;
clear;
close all;

img1 = imread('sample/badminton.jpg');
img2 = imread('sample/basketball.jpeg');

img1_gray = rgb2gray(img1);
[r, c] = size(img1_gray);
img2_gray_resized = imresize(rgb2gray(img2), [r, c]);

fprintf('Select a Bitwise Operation:\n');
fprintf('1. AND\n');
fprintf('2. OR\n');
fprintf('3. NOT (on Image 1)\n');
fprintf('4. XOR\n');

choice = input('Enter your choice (1-4): ');

figure;

switch choice
    case 1
        result = bitand(img1_gray, img2_gray_resized);
        subplot(1, 3, 1); imshow(img1_gray); title('Image 1');
        subplot(1, 3, 2); imshow(img2_gray_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Bitwise AND)');
    case 2
        result = bitor(img1_gray, img2_gray_resized);
        subplot(1, 3, 1); imshow(img1_gray); title('Image 1');
        subplot(1, 3, 2); imshow(img2_gray_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Bitwise OR)');
    case 3
        result = bitcmp(img1_gray);
        subplot(1, 2, 1); imshow(img1_gray); title('Original Image');
        subplot(1, 2, 2); imshow(result); title('Result (Bitwise NOT)');
    case 4
        result = bitxor(img1_gray, img2_gray_resized);
        subplot(1, 3, 1); imshow(img1_gray); title('Image 1');
        subplot(1, 3, 2); imshow(img2_gray_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Bitwise XOR)');
    otherwise
        disp('Invalid choice. Please run the script again.');
end