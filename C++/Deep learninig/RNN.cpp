#include <iostream>
#include <vector>
#include <cmath>

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}
class RNN {
private:
    int intsize;
    int hiddsiz;
    int outsize;
    std::vector<std::vector<double>> a1;
    std::vector<std::vector<double>> b1;
    std::vector<std::vector<double>> c1;
    std::vector<double> b_h;
    std::vector<double> b_y;
public:
    RNN(int intsize, int hiddsiz, int outsize) {
        this->intsize = intsize;
        this->hiddsiz = hiddsiz;
        this->outsize = outsize;
        a1.resize(hiddsiz, std::vector<double>(hiddsiz, 0.0));
        b1.resize(hiddsiz, std::vector<double>(intsize, 0.0));
        c1.resize(outsize, std::vector<double>(hiddsiz, 0.0));
        b_h.resize(hiddsiz, 0.0);
        b_y.resize(outsize, 0.0);
        for (int i = 0; i < hiddsiz; ++i) {
            for (int j = 0; j < hiddsiz; ++j) {
                a1[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }

        for (int i = 0; i < hiddsiz; ++i) {
            for (int j = 0; j < intsize; ++j) {
                b1[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }

        for (int i = 0; i < outsize; ++i) {
            for (int j = 0; j < hiddsiz; ++j) {
                c1[i][j] = ((double)rand() / RAND_MAX) - 0.5;
            }
        }
    }
    std::vector<std::vector<double>> forward(const std::vector<std::vector<double>>& inputs) {
        int seqLen = inputs.size();
        std::vector<std::vector<double>> hiddenStates(seqLen, std::vector<double>(hiddsiz, 0.0));
        std::vector<std::vector<double>> outputs(seqLen, std::vector<double>(outsize, 0.0));
        for (int t = 0; t < seqLen; ++t) {
            if (t == 0) {
                for (int i = 0; i < hiddsiz; ++i) {
                    double sum = 0.0;
                    for (int j = 0; j < intsize; ++j) {
                        sum += b1[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            } else {
                for (int i = 0; i < hiddsiz; ++i) {
                    double sum = 0.0;
                    for (int j = 0; j < hiddsiz; ++j) {
                        sum += a1[i][j] * hiddenStates[t - 1][j];
                    }
                    for (int j = 0; j < intsize; ++j) {
                        sum += b1[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            }
            for (int i = 0; i < outsize; ++i) {
                double sum = 0.0;
                for (int j = 0; j < hiddsiz; ++j) {
                    sum += c1[i][j] * hiddenStates[t][j];
                }
                outputs[t][i] = sum + b_y[i];
            }
        }
        return outputs;
    }
};

int main() {
    int intsize = 1;
    int hiddsiz = 64;
    int outsize = 1;
    RNN rnn(intsize, hiddsiz, outsize);
    std::vector<std::vector<double>> inputs = {{1.0}, {2.0}, {3.0}};
    std::vector<std::vector<double>> output = rnn.forward(inputs);

    for (const auto& o : output) {
        for (const auto& val : o) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

