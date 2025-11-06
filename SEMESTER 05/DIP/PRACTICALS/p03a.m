clc;
clear;
close all;

img_info = imfinfo('sample/badminton.jpg');

fprintf('Metadata Information for: %s\n', img_info.Filename);
fprintf('----------------------------------\n');
fprintf('Image Format: %s\n', img_info.Format);
fprintf('Bit Depth: %d\n', img_info.BitDepth);
fprintf('Color Type: %s\n', img_info.ColorType);
fprintf('Height: %d pixels\n', img_info.Height);
fprintf('Width: %d pixels\n', img_info.Width);
fprintf('File Size: %d bytes\n', img_info.FileSize);