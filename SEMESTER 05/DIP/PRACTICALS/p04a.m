clc;
clear;
close all;

i = imread('sample/cameraman.jpeg');
j = imread('sample/badminton.jpg');

[r, c, ch] = size(i);
j = imresize(j, [r, c]);

disp('Select an operation:');
disp('1. Add two images');
disp('2. Add image with constant value');
disp('3. Subtract two images');
disp('4. Multiply two images');
disp('5. Divide two images');

choice = input('Enter your choice (1-5): ');

result = [];

switch choice
    case 1
        result = i + j;
    case 2
        constant = input('Enter a constant value to add: ');
        result = i + constant;
    case 3
        result = i - j;
    case 4
        result = i .* j;
    case 5
        result = i ./ j;
    otherwise
        disp('Invalid choice. Please select a valid operation.');
end

subplot(131); imshow(i); title('Image 1');
subplot(132); imshow(j); title('Image 2');

if ~isempty(result)
    subplot(133); imshow(result); title('Result');
end
