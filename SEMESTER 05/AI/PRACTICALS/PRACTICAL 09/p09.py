import tensorflow as tf
from tensorflow.keras.applications import MobileNetV2
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.mobilenet_v2 import preprocess_input, decode_predictions
import numpy as np
import os

# Suppress TensorFlow logging (optional, for cleaner output)
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

def classify_local_image(image_path, model):
    """Loads, preprocesses, and classifies a single local image."""
    try:
        # Check if the file exists
        if not os.path.exists(image_path):
            print(f"Error: Image path not found: {image_path}")
            return

        print(f"\nClassifying image: {image_path}")

        # Load and resize the image (MobileNetV2 uses 224x224)
        img = image.load_img(image_path, target_size=(224, 224))
        
        # Convert image to numpy array
        img_array = image.img_to_array(img)
        
        # Expand dimensions to create a "batch" of 1
        img_batch = np.expand_dims(img_array, axis=0)
        
        # Preprocess the image for the model
        img_preprocessed = preprocess_input(img_batch)
        
        # Make prediction
        predictions = model.predict(img_preprocessed, verbose=0)
        
        # Decode the prediction
        decoded = decode_predictions(predictions, top=3)[0]
        
        print("Top 3 predictions:")
        for i, (imagenet_id, label, score) in enumerate(decoded):
            print(f"{i+1}: {label} ({score*100:.2f}%)")
            
    except Exception as e:
        print(f"Error processing {image_path}: {e}")

print("--- Practical 09: CNN Image Classification ---")

# --- 1. Load Pre-trained Model ---
print("Loading pre-trained MobileNetV2 model...")
# We load the model once to be efficient
try:
    model = MobileNetV2(weights='imagenet')
    print("Model loaded successfully.")
    
    # --- 2. Get Image Path from User ---
    # We will ask the user for a local file path
    print("\nPlease provide the full path to a cat or dog image.")
    user_image_path = input("Enter image path: ")

    # --- 3. Classify the Local Image ---
    classify_local_image(user_image_path, model)

except ImportError:
    print("\n--- ERROR ---")
    print("This practical requires TensorFlow.")
    print("Please install it using: pip install tensorflow")
except Exception as e:
    print(f"\nAn error occurred during model loading: {e}")
    print("Please ensure you have an internet connection to download the model weights.")

print("\n--- End of Practical 09 ---")