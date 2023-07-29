import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class cannyEdgeDetection {
    private static final int GAUSSIAN_SIZE = 5;
    private static final double GAUSSIAN_SIGMA = 1.4;
    private static final double LOW_THRESHOLD_RATIO = 0.1;
    private static final double HIGH_THRESHOLD_RATIO = 0.3;

    public static void main(String[] args) {
        try {
            // Load input image
            BufferedImage image = ImageIO.read(new File("Java\\Image Processing\\Canny Edge Detection Algorithm\\dog.jpeg"));

            // Convert the image to grayscale
            BufferedImage grayImage = toGrayScale(image);

            // Apply Gaussian smoothing
            BufferedImage smoothedImage = applyGaussianFilter(grayImage);

            // Apply Sobel operator to calculate gradients
            BufferedImage gradientImage = applySobelOperator(smoothedImage);

            // Perform non-maximum suppression
            BufferedImage suppressedImage = performNonMaxSuppression(gradientImage);

            // Apply double thresholding and hysteresis
            BufferedImage edgesImage = applyDoubleThresholding(suppressedImage);

            // Save the resulting image
            File output = new File("canny_edges.jpg");
            ImageIO.write(edgesImage, "JPEG", output);

            System.out.println("Canny edges saved to canny_edges.jpg");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static BufferedImage toGrayScale(BufferedImage image) {
        BufferedImage grayImage = new BufferedImage(image.getWidth(), image.getHeight(), BufferedImage.TYPE_BYTE_GRAY);

        for (int y = 0; y < image.getHeight(); y++) {
            for (int x = 0; x < image.getWidth(); x++) {
                Color color = new Color(image.getRGB(x, y));
                int gray = (int) (color.getRed() * 0.299 + color.getGreen() * 0.587 + color.getBlue() * 0.114);
                grayImage.setRGB(x, y, new Color(gray, gray, gray).getRGB());
            }
        }

        return grayImage;
    }

    private static BufferedImage applyGaussianFilter(BufferedImage image) {
        int width = image.getWidth();
        int height = image.getHeight();
        BufferedImage smoothedImage = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);

        double[][] gaussianKernel = createGaussianKernel(GAUSSIAN_SIZE, GAUSSIAN_SIGMA);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double sum = 0.0;
                for (int j = 0; j < GAUSSIAN_SIZE; j++) {
                    for (int i = 0; i < GAUSSIAN_SIZE; i++) {
                        int pixelX = x - GAUSSIAN_SIZE / 2 + i;
                        int pixelY = y - GAUSSIAN_SIZE / 2 + j;
                        if (pixelX >= 0 && pixelX < width && pixelY >= 0 && pixelY < height) {
                            Color color = new Color(image.getRGB(pixelX, pixelY));
                            double gray = color.getRed();
                            sum += gray * gaussianKernel[i][j];
                        }
                    }
                }
                int smoothedGray = (int) Math.round(sum);
                smoothedImage.setRGB(x, y, new Color(smoothedGray, smoothedGray, smoothedGray).getRGB());
            }
        }

        return smoothedImage;
    }

    private static double[][] createGaussianKernel(int size, double sigma) {
        double[][] kernel = new double[size][size];
        double sum = 0.0;

        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++) {
                int x = i - size / 2;
                int y = j - size / 2;
                kernel[i][j] = Math.exp(-(x * x + y * y) / (2 * sigma * sigma));
                sum += kernel[i][j];
            }
        }

        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++) {
                kernel[i][j] /= sum;
            }
        }

        return kernel;
    }

    private static BufferedImage applySobelOperator(BufferedImage image) {
        int width = image.getWidth();
        int height = image.getHeight();
        BufferedImage gradientImage = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);

        int[][] sobelX = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1}
        };

        int[][] sobelY = {
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
                        Color color = new Color(image.getRGB(pixelX, pixelY));
                        int gray = color.getRed();
                        gradientX += gray * sobelX[i + 1][j + 1];
                        gradientY += gray * sobelY[i + 1][j + 1];
                    }
                }

                int gradientMagnitude = (int) Math.sqrt(gradientX * gradientX + gradientY * gradientY);
                gradientMagnitude = Math.min(gradientMagnitude, 255);
                gradientImage.setRGB(x, y, new Color(gradientMagnitude, gradientMagnitude, gradientMagnitude).getRGB());
            }
        }

        return gradientImage;
    }

    private static BufferedImage performNonMaxSuppression(BufferedImage image) {
        int width = image.getWidth();
        int height = image.getHeight();
        BufferedImage suppressedImage = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);

        for (int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                int gradientMagnitude = new Color(image.getRGB(x, y)).getRed();
                int angle = (int) (Math.atan2(getGradientY(image, x, y), getGradientX(image, x, y)) * 180 / Math.PI);
                angle = (angle + 180) % 180;

                int neighbor1 = 0;
                int neighbor2 = 0;
                
                if ((angle >= 0 && angle < 22.5) || (angle >= 157.5 && angle < 180)) {
                    neighbor1 = new Color(image.getRGB(x, y - 1)).getRed();
                    neighbor2 = new Color(image.getRGB(x, y + 1)).getRed();
                } else if (angle >= 22.5 && angle < 67.5) {
                    neighbor1 = new Color(image.getRGB(x + 1, y - 1)).getRed();
                    neighbor2 = new Color(image.getRGB(x - 1, y + 1)).getRed();
                } else if (angle >= 67.5 && angle < 112.5) {
                    neighbor1 = new Color(image.getRGB(x + 1, y)).getRed();
                    neighbor2 = new Color(image.getRGB(x - 1, y)).getRed();
                } else if (angle >= 112.5 && angle < 157.5) {
                    neighbor1 = new Color(image.getRGB(x + 1, y + 1)).getRed();
                    neighbor2 = new Color(image.getRGB(x - 1, y - 1)).getRed();
                }

                if (gradientMagnitude >= neighbor1 && gradientMagnitude >= neighbor2) {
                    suppressedImage.setRGB(x, y, new Color(gradientMagnitude, gradientMagnitude, gradientMagnitude).getRGB());
                } else {
                    suppressedImage.setRGB(x, y, new Color(0, 0, 0).getRGB());
                }
            }
        }

        return suppressedImage;
    }

    private static BufferedImage applyDoubleThresholding(BufferedImage image) {
        int width = image.getWidth();
        int height = image.getHeight();
        BufferedImage edgesImage = new BufferedImage(width, height, BufferedImage.TYPE_BYTE_GRAY);

        int lowThreshold = (int) (LOW_THRESHOLD_RATIO * 255);
        int highThreshold = (int) (HIGH_THRESHOLD_RATIO * 255);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int gray = new Color(image.getRGB(x, y)).getRed();
                if (gray >= highThreshold) {
                    edgesImage.setRGB(x, y, new Color(255, 255, 255).getRGB());
                } else if (gray >= lowThreshold) {
                    boolean isStrongNeighbor = false;
                    for (int j = -1; j <= 1; j++) {
                        for (int i = -1; i <= 1; i++) {
                            if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                                int neighborGray = new Color(image.getRGB(x + i, y + j)).getRed();
                                if (neighborGray >= highThreshold) {
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
                        edgesImage.setRGB(x, y, new Color(255, 255, 255).getRGB());
                    } else {
                        edgesImage.setRGB(x, y, new Color(0, 0, 0).getRGB());
                    }
                } else {
                    edgesImage.setRGB(x, y, new Color(0, 0, 0).getRGB());
                }
            }
        }

        return edgesImage;
    }

    private static int getGradientX(BufferedImage image, int x, int y) {
        int[][] sobelX = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1}
        };

        int gx = 0;
        for (int j = -1; j <= 1; j++) {
            for (int i = -1; i <= 1; i++) {
                int pixelX = x + i;
                int pixelY = y + j;
                int gray = new Color(image.getRGB(pixelX, pixelY)).getRed();
                gx += gray * sobelX[i + 1][j + 1];
            }
        }
        return gx;
    }

    private static int getGradientY(BufferedImage image, int x, int y) {
        int[][] sobelY = {
                {1, 2, 1},
                {0, 0, 0},
                {-1, -2, -1}
        };

        int gy = 0;
        for (int j = -1; j <= 1; j++) {
            for (int i = -1; i <= 1; i++) {
                int pixelX = x + i;
                int pixelY = y + j;
                int gray = new Color(image.getRGB(pixelX, pixelY)).getRed();
                gy += gray * sobelY[i + 1][j + 1];
            }
        }
        return gy;
    }
}
