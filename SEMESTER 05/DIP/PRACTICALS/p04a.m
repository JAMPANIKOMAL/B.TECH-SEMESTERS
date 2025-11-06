clc;
clear;
close all;

img1 = imread('sample/badminton.jpg');
img2 = imread('sample/basketball.jpeg');

[r, c, ~] = size(img1);
img2_resized = imresize(img2, [r, c]);

img1_double = im2double(img1);
img2_double_resized = im2double(img2_resized);

constant_val_int = 50;
constant_val_double = 0.5;

fprintf('Select an Arithmetic Operation:\n');
fprintf('1. Add two images\n');
fprintf('2. Subtract two images\n');
fprintf('3. Multiply two images\n');
fprintf('4. Divide two images\n');
fprintf('5. Add constant to image 1\n');
fprintf('6. Subtract constant from image 1\n');
fprintf('7. Multiply image 1 by constant\n');
fprintf('8. Divide image 1 by constant\n');

choice = input('Enter your choice (1-8): ');

figure;

switch choice
    case 1
        result = imadd(img1, img2_resized);
        subplot(1, 3, 1); imshow(img1); title('Image 1');
        subplot(1, 3, 2); imshow(img2_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Addition)');
    case 2
        result = imsubtract(img1, img2_resized);
        subplot(1, 3, 1); imshow(img1); title('Image 1');
        subplot(1, 3, 2); imshow(img2_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Subtraction)');
    case 3
        result = immultiply(img1_double, img2_double_resized);
        subplot(1, 3, 1); imshow(img1_double); title('Image 1');
        subplot(1, 3, 2); imshow(img2_double_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Multiplication)');
    case 4
        result = imdivide(img1_double, img2_double_resized);
        subplot(1, 3, 1); imshow(img1_double); title('Image 1');
        subplot(1, 3, 2); imshow(img2_double_resized); title('Image 2');
        subplot(1, 3, 3); imshow(result); title('Result (Division)');
    case 5
        result = imadd(img1, constant_val_int);
        subplot(1, 2, 1); imshow(img1); title('Original Image');
        subplot(1, 2, 2); imshow(result); title('Result (Add Constant)');
    case 6
        result = imsubtract(img1, constant_val_int);
        subplot(1, 2, 1); imshow(img1); title('Original Image');
        subplot(1, 2, 2); imshow(result); title('Result (Subtract Constant)');
    case 7
        result = immultiply(img1_double, constant_val_double);
        subplot(1, 2, 1); imshow(img1_double); title('Original Image');
        subplot(1, 2, 2); imshow(result); title('Result (Multiply Constant)');
    case 8
        result = imdivide(img1_double, constant_val_double);
        subplot(1, 2, 1); imshow(img1_double); title('Original Image');
        subplot(1, 2, 2); imshow(result); title('Result (Divide Constant)');
    otherwise
        disp('Invalid choice. Please run the script again.');
end