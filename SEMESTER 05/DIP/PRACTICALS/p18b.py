import cv2
import numpy as np
import os
import matplotlib.pyplot as plt
import requests
from tqdm import tqdm
import sys

# --- Config ---
INPUT_IMAGE_PATH = 'sample/18b.png'
MODEL_WEIGHTS_PATH = 'yolov5s.onnx'          
CLASS_NAMES_PATH = 'coco.names'
CONFIDENCE_THRESHOLD = 0.5
NMS_IOU_THRESHOLD = 0.3
ONNX_INPUT_SIZE = 640                       

# --- Download URLs ---
YOLO_URLS = {
    # Option A: grab prebuilt ONNX from the YOLOv5 releases page (v6.1/v7.0 both provide ONNX)
    # If this ever moves, export locally (Option B below in comments).
    'yolov5s.onnx': 'https://github.com/ultralytics/yolov5/releases/download/v7.0/yolov5s.onnx',
    'coco.names': 'https://raw.githubusercontent.com/pjreddie/darknet/master/data/coco.names'
}

def download_file(url, filename):
    print(f"Downloading {filename}...")
    try:
        r = requests.get(url, stream=True)
        r.raise_for_status()
        total = int(r.headers.get('content-length', 0))
        with open(filename, 'wb') as f:
            if total > 0:
                for chunk in tqdm(r.iter_content(1024), total=total // 1024, unit='KB'):
                    f.write(chunk)
            else:
                f.write(r.content)
        print(f"{filename} download successful.")
        return True
    except requests.exceptions.RequestException as e:
        print(f"Error downloading {filename}: {e}")
        return False

def setup_yolo_files(urls):
    print("Checking YOLO files (YOLOv5s ONNX)...")
    for filename, url in urls.items():
        if not os.path.exists(filename):
            print(f"File {filename} not found.")
            if not download_file(url, filename):
                print(f"Fatal error: Could not download {filename}. Exiting.")
                sys.exit(1)
    print("All required files present.")
    return True

def yolo_object_recognition(input_path, weights_path, names_path,
                            conf_thresh, iou_thresh):
    if not setup_yolo_files(YOLO_URLS):
        return

    # Load names
    try:
        with open(names_path, 'r') as f:
            classes = [line.strip() for line in f.readlines()]
    except FileNotFoundError:
        print(f"Error: Class names file not found at {names_path}.")
        return

    # Load ONNX model
    print("Loading YOLOv5s ONNX...")
    net = cv2.dnn.readNetFromONNX(weights_path)
    if net.empty():
        print("Error: Could not load ONNX model.")
        return
    net.setPreferableBackend(cv2.dnn.DNN_BACKEND_OPENCV)
    net.setPreferableTarget(cv2.dnn.DNN_TARGET_CPU)

    img = cv2.imread(input_path)
    if img is None:
        print(f"Error: Could not load image at {input_path}")
        return
    H, W = img.shape[:2]

    # Preprocess (YOLOv5 standard)
    blob = cv2.dnn.blobFromImage(img, 1/255.0, (ONNX_INPUT_SIZE, ONNX_INPUT_SIZE), swapRB=True, crop=False)
    net.setInput(blob)

    # YOLOv5 ONNX usually returns a single output tensor
    outputs = net.forward()
    # outputs shape: (1, N, 85) -> squeeze to (N, 85)
    preds = np.squeeze(outputs)

    boxes, confidences, classIDs = [], [], []

    # Each pred: [cx, cy, w, h, obj, class_probs...]
    for det in preds:
        obj = det[4]
        if obj < 1e-6:  # quick skip
            continue
        class_scores = det[5:]
        classID = int(np.argmax(class_scores))
        conf = float(class_scores[classID] * obj)
        if conf >= conf_thresh:
            cx, cy, w, h = det[0], det[1], det[2], det[3]
            # Scale back to original image size
            x = int((cx - w/2) * W / ONNX_INPUT_SIZE * ONNX_INPUT_SIZE / W)  # keep formula simple next lines
            y = int((cy - h/2) * H / ONNX_INPUT_SIZE * ONNX_INPUT_SIZE / H)

            # Since we resized with letterboxing disabled (crop=False), 
            # directly scale by W/H:
            x = int((cx - w/2) * W)
            y = int((cy - h/2) * H)
            w = int(w * W)
            h = int(h * H)

            boxes.append([x, y, w, h])
            confidences.append(conf)
            classIDs.append(classID)

    idxs = cv2.dnn.NMSBoxes(boxes, confidences, conf_thresh, iou_thresh)

    if len(idxs) > 0:
        for i in idxs.flatten():
            x, y, w, h = boxes[i]
            label = f"{classes[classIDs[i]]}: {confidences[i]:.2f}"
            color = (0, 255, 0)
            cv2.rectangle(img, (x, y), (x+w, y+h), color, 2)
            cv2.putText(img, label, (x, max(10, y-5)),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title("YOLOv5s ONNX — OpenCV DNN")
    plt.axis('off')
    plt.show()

    print(f"\nDetection complete. Found {len(idxs.flatten()) if len(idxs) else 0} objects.")

if __name__ == "__main__":
    yolo_object_recognition(
        INPUT_IMAGE_PATH,
        MODEL_WEIGHTS_PATH,
        CLASS_NAMES_PATH,
        CONFIDENCE_THRESHOLD,
        NMS_IOU_THRESHOLD
    )
