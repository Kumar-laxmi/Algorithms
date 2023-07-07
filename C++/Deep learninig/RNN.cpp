#include <iostream>
#include <vector>
#include <cmath>

// Define the sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Define the RNN class
class RNN {
private:
    int inputSize;
    int hiddenSize;
    int outputSize;
    std::vector<std::vector<double>> W_hh;
    std::vector<std::vector<double>> W_xh;
    std::vector<std::vector<double>> W_hy;
    std::vector<double> b_h;
    std::vector<double> b_y;

public:
    RNN(int inputSize, int hiddenSize, int outputSize) {
        this->inputSize = inputSize;
        this->hiddenSize = hiddenSize;
        this->outputSize = outputSize;

        // Initialize weights
        W_hh.resize(hiddenSize, std::vector<double>(hiddenSize, 0.0));
        W_xh.resize(hiddenSize, std::vector<double>(inputSize, 0.0));
        W_hy.resize(outputSize, std::vector<double>(hiddenSize, 0.0));
        b_h.resize(hiddenSize, 0.0);
        b_y.resize(outputSize, 0.0);

        // Initialize weights with random values
        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                W_hh[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }

        for (int i = 0; i < hiddenSize; ++i) {
            for (int j = 0; j < inputSize; ++j) {
                W_xh[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }

        for (int i = 0; i < outputSize; ++i) {
            for (int j = 0; j < hiddenSize; ++j) {
                W_hy[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }
    }

    std::vector<std::vector<double>> forward(const std::vector<std::vector<double>>& inputs) {
        int seqLen = inputs.size();
        std::vector<std::vector<double>> hiddenStates(seqLen, std::vector<double>(hiddenSize, 0.0));
        std::vector<std::vector<double>> outputs(seqLen, std::vector<double>(outputSize, 0.0));

        // Iterate over each input in the sequence
        for (int t = 0; t < seqLen; ++t) {
            // Update the hidden state
            if (t == 0) {
                for (int i = 0; i < hiddenSize; ++i) {
                    double sum = 0.0;
                    for (int j = 0; j < inputSize; ++j) {
                        sum += W_xh[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            } else {
                for (int i = 0; i < hiddenSize; ++i) {
                    double sum = 0.0;
                    for (int j = 0; j < hiddenSize; ++j) {
                        sum += W_hh[i][j] * hiddenStates[t - 1][j];
                    }
                    for (int j = 0; j < inputSize; ++j) {
                        sum += W_xh[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            }

            // Compute the output
            for (int i = 0; i < outputSize; ++i) {
                double sum = 0.0;
                for (int j = 0; j < hiddenSize; ++j) {
                    sum += W_hy[i][j] * hiddenStates[t][j];
                }
                outputs[t][i] = sum + b_y[i];
            }
        }

        return outputs;
    }
};

int main() {
    int inputSize = 1;
    int hiddenSize = 64;
    int outputSize = 1;

    // Create an RNN instance
    RNN rnn(inputSize, hiddenSize, outputSize);

    // Define the input sequence
    std::vector<std::vector<double>> inputs = {{1.0}, {2.0}, {3.0}};

    // Forward pass
    std::vector<std::vector<double>> output = rnn.forward(inputs);

    // Print the output
    for (const auto& o : output) {
        for (const auto& val : o) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

