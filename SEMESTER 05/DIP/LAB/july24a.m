clc;
clear;
close all;

i = imread("sample/cameraman.jpeg"); % Convert to grayscale
i = rgb2gray(i);

% Display image bounds
fprintf('Image bounds: Rows = 1 to %d, Columns = 1 to %d\n', size(i, 1), size(i, 2));

% Get user input for pixel location
row = input('Enter row number of the pixel: ');
col = input('Enter column number of the pixel: ');

% Check input bounds
if row > 1 && row < size(i, 1) && col > 1 && col < size(i, 2)
    % Get 4 neighbors
    neighbors = [i(row-1, col), i(row+1, col), i(row, col-1), i(row, col+1)];
    
    % Display neighbors with their positions
    fprintf('Top(%d, %d) = %d, Bottom(%d, %d) = %d, Left(%d, %d) = %d, Right(%d, %d) = %d\n', ...
        row-1, col, neighbors(1), row+1, col, neighbors(2), row, col-1, neighbors(3), row, col+1, neighbors(4));
else
    disp('Input pixel is out of image bounds.');
end
