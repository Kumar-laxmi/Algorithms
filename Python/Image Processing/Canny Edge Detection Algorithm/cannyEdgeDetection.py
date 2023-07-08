import cv2
import numpy as np

#showing the original image
image = cv2.imread('Python/Image Processing/Canny Edge Detection Algorithm/dog.jpeg')
cv2.imshow('Original Image', image)
cv2.waitKey(0)

def canny_edge_detection(image, low_threshold, high_threshold):
    # Step 1: Noise Reduction
    blurred = cv2.GaussianBlur(image, (5, 5), 0)

    # Step 2: Gradient Calculation
    gradient_x = cv2.Sobel(blurred, cv2.CV_64F, 1, 0, ksize=3)
    gradient_y = cv2.Sobel(blurred, cv2.CV_64F, 0, 1, ksize=3)
    gradient_magnitude = np.sqrt(gradient_x ** 2 + gradient_y ** 2)
    gradient_direction = np.arctan2(gradient_y, gradient_x)

    # Step 3: Non-maximum Suppression
    suppressed = np.zeros_like(gradient_magnitude)
    height, width = gradient_magnitude.shape[:2]
    angle_quantized = (np.round(gradient_direction * (5.0 / np.pi)) % 4).astype(int)
    for i in range(1, height - 1):
        for j in range(1, width - 1):
            q = angle_quantized[i, j]
            if (gradient_magnitude[i, j] >= gradient_magnitude[i + 1, j + 1]) and \
                    (gradient_magnitude[i, j] >= gradient_magnitude[i - 1, j - 1]):
                suppressed[i, j] = gradient_magnitude[i, j]

    # Step 4: Double Thresholding
    edges = np.zeros_like(suppressed)
    strong_edges = suppressed > high_threshold
    weak_edges = (suppressed >= low_threshold) & (suppressed <= high_threshold)
    edges[strong_edges] = 255

    # Step 5: Hysteresis
    while np.any(weak_edges):
        weak_y, weak_x = np.nonzero(weak_edges)
        current_weak_y, current_weak_x = weak_y[0], weak_x[0]
        edges[current_weak_y, current_weak_x] = 255
        weak_edges[current_weak_y, current_weak_x] = False

        neighbors_y, neighbors_x = np.nonzero(
            np.logical_and(
                weak_edges[current_weak_y - 1:current_weak_y + 2, current_weak_x - 1:current_weak_x + 2],
                np.ones((3, 3))
            )
        )
        for neighbor_y, neighbor_x in zip(neighbors_y, neighbors_x):
            edges[current_weak_y + neighbor_y - 1, current_weak_x + neighbor_x - 1] = 255
            weak_edges[current_weak_y + neighbor_y - 1, current_weak_x + neighbor_x - 1] = False

    return edges

# Load input image
image = cv2.imread('Python/Image Processing/Canny Edge Detection Algorithm/dog.jpeg', cv2.IMREAD_GRAYSCALE)

# Perform Canny edge detection
edges = canny_edge_detection(image, low_threshold=50, high_threshold=150)

# Display the result
cv2.imshow('Canny Edges', edges)
cv2.waitKey(0)
cv2.destroyAllWindows()
