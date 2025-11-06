clc;
clear;
close all;

img = imread('sample/cameraman.jpeg');
if size(img, 3) == 3
    img = rgb2gray(img);
end

[rows, cols] = size(img);
fprintf('Image Size: %d rows x %d columns\n\n', rows, cols);

row = input('Enter row index (e.g., 150): ');
col = input('Enter column index (e.g., 150): ');

if row < 1 || row > rows || col < 1 || col > cols
    disp('Invalid pixel location!');
    return;
end

fprintf('\nSelected Pixel Value at (%d, %d): %d\n', row, col, img(row, col));

% --- 4-Neighbors ---
fprintf('\n--- 4-Neighbors ---\n');
four_neighbors = [-1, 0; 1, 0; 0, -1; 0, 1];
labels_4 = {'Top', 'Bottom', 'Left', 'Right'};

for i = 1:4
    r = row + four_neighbors(i, 1);
    c = col + four_neighbors(i, 2);
    
    if r >= 1 && r <= rows && c >= 1 && c <= cols
        fprintf('%-7s (%d, %d): %d\n', labels_4{i}, r, c, img(r, c));
    else
        fprintf('%-7s (%d, %d): [Out of bounds]\n', labels_4{i}, r, c);
    end
end

% --- 8-Neighbors ---
fprintf('\n--- 8-Neighbors ---\n');
eight_neighbors = [-1, 0; 1, 0; 0, -1; 0, 1; -1, -1; -1, 1; 1, -1; 1, 1];
labels_8 = {'Top', 'Bottom', 'Left', 'Right', 'Top-L', 'Top-R', 'Bot-L', 'Bot-R'};

for i = 1:8
    r = row + eight_neighbors(i, 1);
    c = col + eight_neighbors(i, 2);
    
    if r >= 1 && r <= rows && c >= 1 && c <= cols
        fprintf('%-8s (%d, %d): %d\n', labels_8{i}, r, c, img(r, c));
    else
        fprintf('%-8s (%d, %d): [Out of bounds]\n', labels_8{i}, r, c);
    end
end