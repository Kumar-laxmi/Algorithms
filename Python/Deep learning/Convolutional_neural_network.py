import numpy as np

# Define the input image and labels
input_image = np.array([[1, 0, 1, 0, 1],
                       [0, 1, 0, 1, 0],
                       [1, 0, 1, 0, 1],
                       [0, 1, 0, 1, 0],
                       [1, 0, 1, 0, 1]])

labels = np.array([0, 1, 0])

# Define the filters
filter1 = np.array([[1, 0, -1],
                    [1, 0, -1],
                    [1, 0, -1]])

filter2 = np.array([[-1, -1, -1],
                    [0, 0, 0],
                    [1, 1, 1]])

# Convolution operation
def convolve(image, kernel):
    kernel_size = kernel.shape[0]
    image_size = image.shape[0]
    output_size = image_size - kernel_size + 1

    output = np.zeros((output_size, output_size))

    for i in range(output_size):
        for j in range(output_size):
            output[i, j] = np.sum(image[i:i+kernel_size, j:j+kernel_size] * kernel)

    return output

# Apply convolution to the input image using the filters
convolved_image1 = convolve(input_image, filter1)
convolved_image2 = convolve(input_image, filter2)

# Print the convolved images
print("Convolved Image 1:")
print(convolved_image1)

print("Convolved Image 2:")
print(convolved_image2)
