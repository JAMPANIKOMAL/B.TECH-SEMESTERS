# Practical 09: Build, Train, and Apply a CNN for Cat/Dog Classification
# Save this file as p09.py

import tensorflow as tf
import tensorflow_datasets as tfds
from tensorflow.keras.preprocessing.image import load_img, img_to_array
import numpy as np
import os
import warnings

# Suppress TensorFlow C++ level warnings and general warnings
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
warnings.filterwarnings('ignore')

# --- 1. Define Image Size and Preprocessing ---
IMG_SIZE = (128, 128) # Resize all images to this
BATCH_SIZE = 32

def preprocess(features):
    """Resize, normalize images, and set label."""
    # This dataset has 'species' (1=Cat, 2=Dog)
    # We convert this to 0 (Cat) and 1 (Dog)
    img = tf.image.resize(features['image'], IMG_SIZE)
    img = tf.cast(img, tf.float32) / 255.0
    label = features['species'] - 1
    return img, label

# --- 2. Load and Prepare Dataset ---
def load_dataset():
    """Loads the 'oxford_iiit_pet' dataset and filters for cats/dogs."""
    print("Loading 'oxford_iiit_pet' dataset from TensorFlow Datasets...")
    
    # We use a fixed split based on the dataset's actual size (3680 images)
    # to avoid the 'incompatible slice' error.
    # 80% for train (2944), 20% for validation (736).
    ds_train, ds_val = tfds.load(
        'oxford_iiit_pet',
        split=['train[:2944]', 'train[2944:]'], # 2944 for train, 736 for val
        as_supervised=False # We need the 'species' feature
    )

    # Filter for cats (1) and dogs (2) only.
    ds_train = ds_train.filter(lambda x: x['species'] != 3)
    ds_val = ds_val.filter(lambda x: x['species'] != 3)

    print(f"Loaded training and validation images.")
    
    # Apply preprocessing and batching
    ds_train = ds_train.map(preprocess).batch(BATCH_SIZE).prefetch(tf.data.AUTOTUNE)
    ds_val = ds_val.map(preprocess).batch(BATCH_SIZE).prefetch(tf.data.AUTOTUNE)
    return ds_train, ds_val

# --- 3. Build the 3-Layer CNN Model ---
def build_model():
    """Builds a 3-layer CNN model."""
    print("Building 3-layer CNN model...")
    model = tf.keras.models.Sequential([
        # Input Layer
        tf.keras.layers.Input(shape=(IMG_SIZE[0], IMG_SIZE[1], 3)),
        
        # 1st Conv Layer
        tf.keras.layers.Conv2D(32, (3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(2, 2),
        
        # 2nd Conv Layer
        tf.keras.layers.Conv2D(64, (3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(2, 2),
        
        # 3rd Conv Layer
        tf.keras.layers.Conv2D(128, (3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(2, 2),
        
        # Flatten and Dense Layers
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(512, activation='relu'),
        tf.keras.layers.Dense(1, activation='sigmoid') # 1 output: 0 for Cat, 1 for Dog
    ])
    
    model.compile(
        optimizer='adam',
        loss='binary_crossentropy', # Use binary_crossentropy for 2 classes
        metrics=['accuracy']
    )
    return model

# --- 4. Classify a Local Image ---
def classify_local_image(model, image_path):
    """Loads a local image, preprocesses it, and predicts."""
    try:
        img = load_img(image_path, target_size=IMG_SIZE)
        img_array = img_to_array(img)
        img_array = tf.expand_dims(img_array, 0) # Create a batch
        img_array = img_array / 255.0 # Normalize

        prediction = model.predict(img_array)
        
        print("\n--- Prediction Result ---")
        if prediction[0] > 0.5:
            print(f"Prediction: DOG ({prediction[0][0]*100:.2f}%)")
        else:
            print(f"Prediction: CAT ({(1-prediction[0][0])*100:.2f}%)")
            
    except Exception as e:
        print(f"Error classifying image: {e}")

# --- Main Execution ---
print("--- Practical 09: Build & Train a CNN ---")
try:
    # 1. Load Data
    ds_train, ds_val = load_dataset()
    
    # 2. Build Model
    model = build_model()
    model.summary()
    
    # 3. Train Model
    print("\n--- Starting Model Training ---")
    EPOCHS = 5
    history = model.fit(
        ds_train,
        epochs=EPOCHS,
        validation_data=ds_val
    )
    print("--- Model Training Complete ---")

    # 4. Classify User Image
    print("\nPlease provide the full path to a cat or dog image.")
    image_path = input("Enter image path: ")
    
    if os.path.exists(image_path):
        classify_local_image(model, image_path)
    else:
        print("Error: File path not found.")

except Exception as e:
    print(f"\nAn error occurred: {e}")
    print("Please ensure you have an internet connection to download the dataset.")

print("\n--- End of Practical 09 ---")