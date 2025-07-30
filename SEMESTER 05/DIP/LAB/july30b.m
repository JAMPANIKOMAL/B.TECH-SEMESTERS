% Logarithmic Transformation(use pout, chestx-ray and spine images)

clc;
clear;
close all;

% Read images from the sample directory
imageFiles = ["pout.tif", "chestXray.tif", "spine.tif"];
numImages = length(imageFiles);

% Initialize a figure for displaying the results
figure;

for k = 1:numImages
    % Read each image
    img = imread(fullfile("sample", imageFiles(k)));
    
    % Convert to double for logarithmic transformation
    imgDouble = im2double(img);
    
    % Apply logarithmic transformation
    logTransformed = log(1 + imgDouble);
    
    % Display original and transformed images
    subplot(numImages, 2, 2*k-1);
    imshow(img);
    title(['Original Image: ', imageFiles(k)]);
    
    subplot(numImages, 2, 2*k);
    imshow(logTransformed);
    title(['Log Transformed Image: ', imageFiles(k)]);
end