# 16B) Python script to perform various OpenCV tasks on foosball.png

import cv2
import numpy as np
from matplotlib import pyplot as plt

# --- Step 1: Load Foosball image ---
# Load the image using OpenCV. It's loaded in BGR format by default.
try:
    image_bgr = cv2.imread('sample/foosball.png')
    if image_bgr is None:
        raise FileNotFoundError
    # Convert from BGR to RGB for correct color display with Matplotlib
    image_rgb = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2RGB)
except FileNotFoundError:
    print("Error: 'foosball.png' not found. Please ensure the image file is in the same directory as the script.")
    exit()


# --- Step 2: Print image height, width, channels ---
# Get the dimensions of the image from its shape
height, width, channels = image_rgb.shape
print(f"Image Details:")
print(f"  Height: {height} pixels")
print(f"  Width:  {width} pixels")
print(f"  Channels: {channels}\n")


# --- Step 3: Convert & display grayscale image ---
gray_image = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2GRAY)


# --- Step 4: Rotate image by 100° ---
# Calculate the center of the image
center = (width // 2, height // 2)
# Get the rotation matrix for a 100-degree rotation
rotation_matrix = cv2.getRotationMatrix2D(center, 100, 1.0)
# Apply the affine transformation (rotation)
rotated_image = cv2.warpAffine(image_rgb, rotation_matrix, (width, height))


# --- Step 5: Crop center of image ---
# Define the start and end coordinates for the crop (center 50%)
start_row, end_row = int(height * 0.25), int(height * 0.75)
start_col, end_col = int(width * 0.25), int(width * 0.75)
cropped_image = image_rgb[start_row:end_row, start_col:end_col]


# --- Step 6: Show 2x2 plots using Matplotlib ---
# Create a figure with a 2x2 subplot layout
fig, axs = plt.subplots(2, 2, figsize=(10, 8))
fig.suptitle('OpenCV Image Manipulations', fontsize=16)

# Original Image
axs[0, 0].imshow(image_rgb)
axs[0, 0].set_title('1. Original RGB Image')
axs[0, 0].axis('off')

# Grayscale Image
axs[0, 1].imshow(gray_image, cmap='gray')
axs[0, 1].set_title('2. Grayscale Image')
axs[0, 1].axis('off')

# Rotated Image
axs[1, 0].imshow(rotated_image)
axs[1, 0].set_title('3. Rotated 100°')
axs[1, 0].axis('off')

# Cropped Image
axs[1, 1].imshow(cropped_image)
axs[1, 1].set_title('4. Center Cropped')
axs[1, 1].axis('off')

plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()


# --- Step 7 & 8: Plot histogram and apply equalization ---
# Apply histogram equalization to the grayscale image
equalized_image = cv2.equalizeHist(gray_image)


# --- Step 9: Compare original vs equalized image and their histograms ---
plt.figure(figsize=(12, 10))
plt.suptitle('Histogram Equalization Comparison', fontsize=16)

# Original Grayscale Image
plt.subplot(2, 2, 1)
plt.imshow(gray_image, cmap='gray')
plt.title('Original Grayscale Image')
plt.axis('off')

# Histogram of Original Image
plt.subplot(2, 2, 2)
plt.hist(gray_image.ravel(), 256, [0, 256])
plt.title('Original Histogram')
plt.xlabel('Intensity')
plt.ylabel('Pixel Count')

# Equalized Image
plt.subplot(2, 2, 3)
plt.imshow(equalized_image, cmap='gray')
plt.title('Equalized Image')
plt.axis('off')

# Histogram of Equalized Image
plt.subplot(2, 2, 4)
plt.hist(equalized_image.ravel(), 256, [0, 256])
plt.title('Equalized Histogram')
plt.xlabel('Intensity')
plt.ylabel('Pixel Count')

plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()
