clc;
clear;
close all;

files = {'pout.tif', 'spine.tif', 'foosball.png'};
num_files = length(files);

figure; 

for k = 1:num_files
    img_path = ['sample/', files{k}];
    img = imread(img_path);

    if size(img, 3) == 3
        img = rgb2gray(img);
    end
    
    img_double = double(img);

    s_min = 0;
    s_max = 255;
    
    r_min = min(img_double(:));
    r_max = max(img_double(:));

    stretched_img = (img_double - r_min) * (s_max - s_min) / (r_max - r_min) + s_min;
    stretched_img = uint8(stretched_img);
    
    subplot(num_files, 2, (k-1)*2 + 1);
    imshow(img);
    title(['Original: ', files{k}]);
    
    subplot(num_files, 2, (k-1)*2 + 2);
    imshow(stretched_img);
    title('Contrast Stretched');
end