#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

class ConvolutionalNeuralNetwork {
private:
    vector<Matrix> filters;
    vector<double> biases;

public:
    ConvolutionalNeuralNetwork() {
        // Initialize filters and biases here
    }

    Matrix convolution(const Matrix& input) {
        int inputHeight = input.size();
        int inputWidth = input[0].size();
        int numFilters = filters.size();
        int filterSize = filters[0].size();
        int outputHeight = inputHeight - filterSize + 1;
        int outputWidth = inputWidth - filterSize + 1;

        Matrix convolvedFeatures(numFilters, vector<double>(outputWidth, 0.0));

        for (int k = 0; k < numFilters; k++) {
            for (int i = 0; i < outputHeight; i++) {
                for (int j = 0; j < outputWidth; j++) {
                    convolvedFeatures[k][j] += convolveRegion(input, i, j, filters[k]);
                }
            }
        }

        return convolvedFeatures;
    }

    double convolveRegion(const Matrix& input, int startX, int startY, const Matrix& filter) {
        double sum = 0.0;
        int filterSize = filter.size();

        for (int i = 0; i < filterSize; i++) {
            for (int j = 0; j < filterSize; j++) {
                sum += input[startX + i][startY + j] * filter[i][j];
            }
        }

        return sum;
    }

    Matrix maxPooling(const Matrix& input, int poolSize) {
        int inputHeight = input.size();
        int inputWidth = input[0].size();
        int outputHeight = inputHeight / poolSize;
        int outputWidth = inputWidth / poolSize;

        Matrix pooledFeatures(outputHeight, vector<double>(outputWidth, 0.0));

        for (int i = 0; i < outputHeight; i++) {
            for (int j = 0; j < outputWidth; j++) {
                double maxVal = numeric_limits<double>::min();

                for (int m = 0; m < poolSize; m++) {
                    for (int n = 0; n < poolSize; n++) {
                        double value = input[i * poolSize + m][j * poolSize + n];

                        if (value > maxVal) {
                            maxVal = value;
                        }
                    }
                }

                pooledFeatures[i][j] = maxVal;
            }
        }

        return pooledFeatures;
    }

    vector<double> forwardPropagation(const Matrix& input) {
        Matrix convolvedFeatures = convolution(input);
        Matrix pooledFeatures = maxPooling(convolvedFeatures, 2);
        int numFilters = filters.size();
        int pooledHeight = pooledFeatures.size();
        int pooledWidth = pooledFeatures[0].size();

        vector<double> flattenedFeatures(numFilters * pooledHeight * pooledWidth);
        int index = 0;

        for (int k = 0; k < numFilters; k++) {
            for (int i = 0; i < pooledHeight; i++) {
                for (int j = 0; j < pooledWidth; j++) {
                    flattenedFeatures[index++] = pooledFeatures[i][j];
                }
            }
        }

        vector<double> scores(biases.size(), 0.0);

        for (int i = 0; i < biases.size(); i++) {
            for (int j = 0; j < flattenedFeatures.size(); j++) {
                scores[i] += flattenedFeatures[j] * filters[i][j];
            }

            scores[i] += biases[i];
        }

        return scores;
    }
};

int main() {
    ConvolutionalNeuralNetwork cnn;

    // Provide input data
    Matrix input = {
        {0.2, 0.3, 0.4, 0.5},
        {0.3, 0.4, 0.5, 0.6},
        {0.4, 0.5, 0.6, 0.7},
        {0.5, 0.6, 0.7, 0.8}
    };

    vector<double> scores = cnn.forwardPropagation(input);

    // Process the output scores
    // ...

    return 0;
}

