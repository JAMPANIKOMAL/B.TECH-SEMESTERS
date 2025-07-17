clc;
clear;
close all;

i = imread('sample/cameraman.jpeg');
j = imread('sample/badminton.jpg');

[r, c, ch] = size(i);
j = imresize(j, [r, c]);

disp('Select an operation:');
disp('1. And');
disp('2. Or');
disp('3. Not');
disp('4. XOR');

choice = input('Enter your choice (1-4): ');

result = [];

switch choice
    case 1
        result = bitand(i, j);
    case 2
        result = bitor(i, j);
    case 3
        result = bitcmp(i);
    case 4
        result = bitxor(i, j);
    otherwise
        disp('Invalid choice. Please select a valid operation.');
end

subplot(1, 3, 1); imshow(i); title('Image 1');
subplot(1, 3, 2); imshow(j); title('Image 2');

if ~isempty(result)
    subplot(1, 3, 3); imshow(result); title('Result');
end
