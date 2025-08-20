% Aim: To apply distance measure 3 (Euclidean, City Block, Chess Board Distance) 10b

clc;
clear;
close all;

% Read the image
img = imread("sample/cameraman.jpeg");

% Convert image to grayscale if it is not already
if size(img, 3) == 3
    img = rgb2gray(img);
end

% Define the distance measures
euclidean_distance = @(x, y) sqrt(sum((x - y).^2));
city_block_distance = @(x, y) sum(abs(x - y));
chess_board_distance = @(x, y) max(abs(x - y));

% Example usage of distance measures
% Define two sample pixel values for demonstration
pixel1 = double(img(1, 1)); % Pixel value at (1, 1)
pixel2 = double(img(2, 2)); % Pixel value at (2, 2)

% Calculate distances
euclidean_dist = euclidean_distance(pixel1, pixel2);
city_block_dist = city_block_distance(pixel1, pixel2);
chess_board_dist = chess_board_distance(pixel1, pixel2);

% Display results
fprintf('Euclidean Distance: %.2f\n', euclidean_dist);
fprintf('City Block Distance: %.2f\n', city_block_dist);
fprintf('Chess Board Distance: %.2f\n', chess_board_dist);

% User input for coordinates
x1 = input('Enter x1: ');
y1 = input('Enter y1: ');
x2 = input('Enter x2: ');
y2 = input('Enter y2: ');

% Calculate distances based on user input
euclidean_dist_user = sqrt((x2 - x1)^2 + (y2 - y1)^2);
cityblock_dist_user = abs(x2 - x1) + abs(y2 - y1);
chessboard_dist_user = max(abs(x2 - x1), abs(y2 - y1));

% Display results for user input
disp(['Euclidean Distance: ', num2str(euclidean_dist_user)]);
disp(['Cityblock Distance: ', num2str(cityblock_dist_user)]);
disp(['Chessboard Distance: ', num2str(chessboard_dist_user)]);

% Display the image and plot the points
imshow(img);
hold on;
plot(x1, y1, 'ro', 'MarkerSize', 8, 'LineWidth', 2);
plot(x2, y2, 'go', 'MarkerSize', 8, 'LineWidth', 2);
line([x1 x2], [y1 y2], 'Color', 'y', 'LineWidth', 2);
hold off;
title('Selected Points and Connecting Line');