import tensorflow as tf
import tensorflow_datasets as tfds
from tensorflow.keras import layers, models
from tensorflow.keras.preprocessing import image
import numpy as np
import os

# Suppress TensorFlow logging (optional, for cleaner output)
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

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
    
    # Load the dataset. 'as_supervised=False' gives us the feature dictionary.
    ds_train, ds_val = tfds.load(
        'oxford_iiit_pet',
        split=['train[:80%]', 'train[80%:]'],
        as_supervised=False # We need the 'species' feature
    )

    # Filter for cats (1) and dogs (2) only.
    ds_train = ds_train.filter(lambda x: x['species'] != 3)
    ds_val = ds_val.filter(lambda x: x['species'] != 3)

    print(f"Loaded {len(ds_train)} training images and {len(ds_val)} validation images.")
    
    # Apply preprocessing and batching
    ds_train = ds_train.map(preprocess).batch(BATCH_SIZE).prefetch(tf.data.AUTOTUNE)
    ds_val = ds_val.map(preprocess).batch(BATCH_SIZE).prefetch(tf.data.AUTOTUNE)
    return ds_train, ds_val

# --- 3. Build the 3-Layer CNN Model ---
def build_model():
    """Builds a simple 3-layer CNN."""
    print("Building 3-layer CNN model...")
    model = models.Sequential([
        # Input layer (shape matches our resized images)
        layers.Input(shape=(IMG_SIZE[0], IMG_SIZE[1], 3)),
        
        # Layer 1
        layers.Conv2D(32, (3, 3), activation='relu'),
        layers.MaxPooling2D((2, 2)),
        
        # Layer 2
        layers.Conv2D(64, (3, 3), activation='relu'),
        layers.MaxPooling2D((2, 2)),
        
        # Layer 3
        layers.Conv2D(128, (3, 3), activation='relu'),
        layers.MaxPooling2D((2, 2)),
        
        # Classifier layers
        layers.Flatten(),
        layers.Dense(128, activation='relu'),
        layers.Dense(1, activation='sigmoid') # Sigmoid for binary (cat/dog)
    ])
    
    model.compile(
        optimizer='adam',
        loss='binary_crossentropy',
        metrics=['accuracy']
    )
    return model

# --- 4. Function to Classify a Local Image ---
def classify_local_image(image_path, model):
    """Loads, preprocesses, and classifies a single local image."""
    try:
        if not os.path.exists(image_path):
            print(f"Error: Image path not found: {image_path}")
            return

        print(f"\nClassifying image: {image_path}")
        
        img = image.load_img(image_path, target_size=IMG_SIZE)
        img_array = image.img_to_array(img)
        img_array = img_array / 255.0 # Normalize
        img_batch = np.expand_dims(img_array, axis=0) # Create batch
        
        prediction = model.predict(img_batch, verbose=0)[0][0]
        
        print("\n--- Prediction Result ---")
        if prediction < 0.5:
            print(f"Result: CAT ({100*(1-prediction):.2f}%)")
        else:
            print(f"Result: DOG ({100*prediction:.2f}%)")
            
    except Exception as e:
        print(f"Error processing {image_path}: {e}")

# --- Main Execution ---
print("--- Practical 09: Build & Train a CNN ---")
try:
    # 1. Load Data
    ds_train, ds_val = load_dataset()
    
    # 2. Build Model
    model = build_model()
    model.summary() # Print model structure
    
    # 3. Train Model
    print("\n--- Starting Model Training ---")
    # We train for only 3 epochs so it finishes quickly
    model.fit(
        ds_train,
        validation_data=ds_val,
        epochs=3
    )
    print("--- Model Training Finished ---")

    # 4. Get User Image and Classify
    print("\nPlease provide the full path to a cat or dog image to test.")
    user_image_path = input("Enter image path: ")
    classify_local_image(user_image_path, model)

except ImportError:
    print("\n--- ERROR ---")
    print("This practical requires TensorFlow and TensorFlow Datasets.")
    print("Please install them using: pip install tensorflow tensorflow-datasets")
except Exception as e:
    print(f"\nAn error occurred: {e}")
    print("Please ensure you have an internet connection to download the dataset.")

print("\n--- End of Practical 09 ---")