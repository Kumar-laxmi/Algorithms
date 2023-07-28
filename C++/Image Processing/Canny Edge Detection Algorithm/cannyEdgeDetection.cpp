#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace cv;

void toGrayScale(Mat& image);
void applyGaussianFilter(Mat& image);
void applySobelOperator(Mat& image, Mat& gradientImage);
void performNonMaxSuppression(Mat& gradientImage, Mat& suppressedImage);
void applyDoubleThresholding(Mat& suppressedImage, Mat& edgesImage);

int main() {
    // Load input image
    Mat image = imread("dog.jpeg", IMREAD_COLOR);
    if (image.empty()) {
        std::cout << "Error opening the input image file." << std::endl;
        return 1;
    }

    // Convert the image to grayscale
    toGrayScale(image);

    // Apply Gaussian smoothing
    applyGaussianFilter(image);

    // Apply Sobel operator to calculate gradients
    Mat gradientImage;
    applySobelOperator(image, gradientImage);

    // Perform non-maximum suppression
    Mat suppressedImage;
    performNonMaxSuppression(gradientImage, suppressedImage);

    // Apply double thresholding and hysteresis
    Mat edgesImage;
    applyDoubleThresholding(suppressedImage, edgesImage);

    // Display the original and final images
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Canny Edges", WINDOW_NORMAL);
    imshow("Original Image", image);
    imshow("Canny Edges", edgesImage);
    waitKey(0);

    // Save the resulting image
    imwrite("canny_edges.jpg", edgesImage);

    std::cout << "Canny edges saved to canny_edges.jpg" << std::endl;

    return 0;
}

void toGrayScale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyGaussianFilter(Mat& image) {
    GaussianBlur(image, image, Size(5, 5), 0);
}

void applySobelOperator(Mat& image, Mat& gradientImage) {
    Mat gradientX, gradientY;
    Sobel(image, gradientX, CV_32F, 1, 0, 3);
    Sobel(image, gradientY, CV_32F, 0, 1, 3);
    magnitude(gradientX, gradientY, gradientImage);
}

void performNonMaxSuppression(Mat& gradientImage, Mat& suppressedImage) {
    Mat gradientDirection;
    phase(gradientImage, gradientDirection);

    int height = gradientImage.rows;
    int width = gradientImage.cols;

    suppressedImage = Mat(height, width, CV_32F, Scalar(0));

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            float gradientMagnitude = gradientImage.at<float>(y, x);
            float gradientAngle = gradientDirection.at<float>(y, x);

            float q = round(gradientAngle * (5.0 / CV_PI)) / 5.0;

            if ((gradientMagnitude >= gradientImage.at<float>(y + 1, x + 1)) &&
                (gradientMagnitude >= gradientImage.at<float>(y - 1, x - 1))) {
                suppressedImage.at<float>(y, x) = gradientMagnitude;
            }
        }
    }
}

void applyDoubleThresholding(Mat& suppressedImage, Mat& edgesImage) {
    int lowThreshold = 50;
    int highThreshold = 150;

    edgesImage = Mat(suppressedImage.size(), CV_8U, Scalar(0));

    for (int y = 0; y < suppressedImage.rows; y++) {
        for (int x = 0; x < suppressedImage.cols; x++) {
            float gradientMagnitude = suppressedImage.at<float>(y, x);

            if (gradientMagnitude >= highThreshold) {
                edgesImage.at<uchar>(y, x) = 255;
            }
            else if (gradientMagnitude >= lowThreshold) {
                bool isStrongNeighbor = false;
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        if (x + i >= 0 && x + i < suppressedImage.cols && y + j >= 0 && y + j < suppressedImage.rows) {
                            float neighborMagnitude = suppressedImage.at<float>(y + j, x + i);
                            if (neighborMagnitude >= highThreshold) {
                                isStrongNeighbor = true;
                                break;
                            }
                        }
                    }
                    if (isStrongNeighbor) {
                        break;
                    }
                }
                if (isStrongNeighbor) {
                    edgesImage.at<uchar>(y, x) = 255;
                }
            }
        }
    }
}
