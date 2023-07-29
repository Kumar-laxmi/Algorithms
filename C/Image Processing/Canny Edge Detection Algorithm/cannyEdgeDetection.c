#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI
#define GAUSSIAN_SIZE 5
#define GAUSSIAN_SIGMA 1.4
#define SOBEL_SIZE 3
#define LOW_THRESHOLD_RATIO 0.1
#define HIGH_THRESHOLD_RATIO 0.3

void toGrayScale(unsigned char* image, int width, int height);
void applyGaussianFilter(unsigned char* image, int width, int height);
void createGaussianKernel(double kernel[][GAUSSIAN_SIZE], int size, double sigma);
void applySobelOperator(unsigned char* image, int width, int height, unsigned char* gradientImage);
void performNonMaxSuppression(unsigned char* gradientImage, int width, int height, unsigned char* suppressedImage);
void applyDoubleThresholding(unsigned char* suppressedImage, int width, int height, unsigned char* edgesImage);

int main() {
    // Load input image
    FILE* file = fopen("dog.raw", "rb");
    if (file == NULL) {
        printf("Error opening the input image file.\n");
        return 1;
    }
    int width = 640;
    int height = 480;
    unsigned char* image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Convert the image to grayscale
    toGrayScale(image, width, height);

    // Apply Gaussian smoothing
    applyGaussianFilter(image, width, height);

    // Apply Sobel operator to calculate gradients
    unsigned char* gradientImage = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    applySobelOperator(image, width, height, gradientImage);

    // Perform non-maximum suppression
    unsigned char* suppressedImage = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    performNonMaxSuppression(gradientImage, width, height, suppressedImage);

    // Apply double thresholding and hysteresis
    unsigned char* edgesImage = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    applyDoubleThresholding(suppressedImage, width, height, edgesImage);

    // Save the resulting image
    file = fopen("canny_edges.raw", "wb");
    if (file == NULL) {
        printf("Error opening the output image file.\n");
        return 1;
    }
    fwrite(edgesImage, sizeof(unsigned char), width * height, file);
    fclose(file);

    printf("Canny edges saved to canny_edges.raw\n");

    // Free memory
    free(image);
    free(gradientImage);
    free(suppressedImage);
    free(edgesImage);

    return 0;
}

void toGrayScale(unsigned char* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char red = image[3 * i];
        unsigned char green = image[3 * i + 1];
        unsigned char blue = image[3 * i + 2];
        unsigned char gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);
        image[3 * i] = gray;
        image[3 * i + 1] = gray;
        image[3 * i + 2] = gray;
    }
}

void applyGaussianFilter(unsigned char* image, int width, int height) {
    double gaussianKernel[GAUSSIAN_SIZE][GAUSSIAN_SIZE];
    createGaussianKernel(gaussianKernel, GAUSSIAN_SIZE, GAUSSIAN_SIGMA);

    unsigned char* smoothed = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double sum = 0.0;
            for (int j = 0; j < GAUSSIAN_SIZE; j++) {
                for (int i = 0; i < GAUSSIAN_SIZE; i++) {
                    int pixelX = x - GAUSSIAN_SIZE / 2 + i;
                    int pixelY = y - GAUSSIAN_SIZE / 2 + j;
                    if (pixelX >= 0 && pixelX < width && pixelY >= 0 && pixelY < height) {
                        int gray = image[pixelY * width + pixelX];
                        sum += gray * gaussianKernel[i][j];
                    }
                }
            }
            int smoothedGray = (int)round(sum);
            smoothed[y * width + x] = smoothedGray;
        }
    }

    memcpy(image, smoothed, width * height * sizeof(unsigned char));
    free(smoothed);
}

void createGaussianKernel(double kernel[][GAUSSIAN_SIZE], int size, double sigma) {
    double sum = 0.0;

    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            int x = i - size / 2;
            int y = j - size / 2;
            kernel[i][j] = exp(-(x * x + y * y) / (2 * sigma * sigma));
            sum += kernel[i][j];
        }
    }

    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            kernel[i][j] /= sum;
        }
    }
}

void applySobelOperator(unsigned char* image, int width, int height, unsigned char* gradientImage) {
    int sobelX[SOBEL_SIZE][SOBEL_SIZE] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int sobelY[SOBEL_SIZE][SOBEL_SIZE] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int gradientX = 0;
            int gradientY = 0;

            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int pixelX = x + i;
                    int pixelY = y + j;
                    int gray = image[pixelY * width + pixelX];
                    gradientX += gray * sobelX[i + 1][j + 1];
                    gradientY += gray * sobelY[i + 1][j + 1];
                }
            }

            int gradientMagnitude = (int)sqrt(gradientX * gradientX + gradientY * gradientY);
            gradientImage[y * width + x] = gradientMagnitude;
        }
    }
}

void performNonMaxSuppression(unsigned char* gradientImage, int width, int height, unsigned char* suppressedImage) {
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int gradientMagnitude = gradientImage[y * width + x];
            int angle = (int)(atan2((double)getGradientY(gradientImage, x, y, width), (double)getGradientX(gradientImage, x, y, width)) * 180.0 / M_PI);
            angle = (angle + 180) % 180;

            int neighbor1 = 0;
            int neighbor2 = 0;

            if ((angle >= 0 && angle < 22.5) || (angle >= 157.5 && angle < 180)) {
                neighbor1 = gradientImage[(y - 1) * width + x];
                neighbor2 = gradientImage[(y + 1) * width + x];
            }
            else if (angle >= 22.5 && angle < 67.5) {
                neighbor1 = gradientImage[(y - 1) * width + (x + 1)];
                neighbor2 = gradientImage[(y + 1) * width + (x - 1)];
            }
            else if (angle >= 67.5 && angle < 112.5) {
                neighbor1 = gradientImage[y * width + (x + 1)];
                neighbor2 = gradientImage[y * width + (x - 1)];
            }
            else if (angle >= 112.5 && angle < 157.5) {
                neighbor1 = gradientImage[(y - 1) * width + (x - 1)];
                neighbor2 = gradientImage[(y + 1) * width + (x + 1)];
            }

            if (gradientMagnitude >= neighbor1 && gradientMagnitude >= neighbor2) {
                suppressedImage[y * width + x] = gradientMagnitude;
            }
            else {
                suppressedImage[y * width + x] = 0;
            }
        }
    }
}

void applyDoubleThresholding(unsigned char* suppressedImage, int width, int height, unsigned char* edgesImage) {
    int lowThreshold = (int)(LOW_THRESHOLD_RATIO * 255);
    int highThreshold = (int)(HIGH_THRESHOLD_RATIO * 255);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int gray = suppressedImage[y * width + x];
            if (gray >= highThreshold) {
                edgesImage[y * width + x] = 255;
            }
            else if (gray >= lowThreshold) {
                int isStrongNeighbor = 0;
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                            int neighborGray = suppressedImage[(y + j) * width + (x + i)];
                            if (neighborGray >= highThreshold) {
                                isStrongNeighbor = 1;
                                break;
                            }
                        }
                    }
                    if (isStrongNeighbor) {
                        break;
                    }
                }
                if (isStrongNeighbor) {
                    edgesImage[y * width + x] = 255;
                }
                else {
                    edgesImage[y * width + x] = 0;
                }
            }
            else {
                edgesImage[y * width + x] = 0;
            }
        }
    }
}

int getGradientX(unsigned char* image, int x, int y, int width) {
    int sobelX[SOBEL_SIZE][SOBEL_SIZE] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gx = 0;
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            int pixelX = x + i;
            int pixelY = y + j;
            int gray = image[pixelY * width + pixelX];
            gx += gray * sobelX[i + 1][j + 1];
        }
    }
    return gx;
}

int getGradientY(unsigned char* image, int x, int y, int width) {
    int sobelY[SOBEL_SIZE][SOBEL_SIZE] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };

    int gy = 0;
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            int pixelX = x + i;
            int pixelY = y + j;
            int gray = image[pixelY * width + pixelX];
            gy += gray * sobelY[i + 1][j + 1];
        }
    }
    return gy;
}
