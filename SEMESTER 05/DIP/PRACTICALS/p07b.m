clc;
clear;
close all;

imageFiles = {'tire.tif', 'spine.tif'};
gamma_values = [0.4, 2.0, 2.5];

for i = 1:length(imageFiles)
    img_path = ['sample/', imageFiles{i}];
    img = imread(img_path);
    
    if size(img, 3) == 3
        img = rgb2gray(img);
    end
    
    img_double = im2double(img);

    figure;
    
    % Plot Original
    subplot(2, 2, 1);
    imshow(img_double);
    title('Original Image');

    % Plot Gamma 1 (0.4)
    img_gamma_1 = img_double .^ gamma_values(1);
    subplot(2, 2, 2);
    imshow(img_gamma_1);
    title(['Gamma = ', num2str(gamma_values(1))]);

    % Plot Gamma 2 (2.0)
    img_gamma_2 = img_double .^ gamma_values(2);
    subplot(2, 2, 3);
    imshow(img_gamma_2);
    title(['Gamma = ', num2str(gamma_values(2))]);

    % Plot Gamma 3 (2.5)
    img_gamma_3 = img_double .^ gamma_values(3);
    subplot(2, 2, 4);
    imshow(img_gamma_3);
    title(['Gamma = ', num2str(gamma_values(3))]);

    sgtitle(['Power Law (Gamma) for: ', imageFiles{i}]);
end