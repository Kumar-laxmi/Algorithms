import java.util.Arrays;

public class RNN {
    private int inputSize;
    private int hiddenSize;
    private int outputSize;
    private double[][] W_hh;
    private double[][] W_xh;
    private double[][] W_hy;
    private double[] b_h;
    private double[] b_y;
    public RNN(int inputSize, int hiddenSize, int outputSize) {
        this.inputSize = inputSize;
        this.hiddenSize = hiddenSize;
        this.outputSize = outputSize;
        W_hh = new double[hiddenSize][hiddenSize];
        W_xh = new double[hiddenSize][inputSize];
        W_hy = new double[outputSize][hiddenSize];
        b_h = new double[hiddenSize];
        b_y = new double[outputSize];
        for (int i = 0; i < hiddenSize; i++) {
            for (int j = 0; j < hiddenSize; j++) {
                W_hh[i][j] = Math.random() - 0.5;
            }
        }
        for (int i = 0; i < hiddenSize; i++) {
            for (int j = 0; j < inputSize; j++) {
                W_xh[i][j] = Math.random() - 0.5;
            }
        }
        for (int i = 0; i < outputSize; i++) {
            for (int j = 0; j < hiddenSize; j++) {
                W_hy[i][j] = Math.random() - 0.5;
            }
        }
    }
    public double[][] forward(double[][] inputs) {
        int seqLen = inputs.length;
        double[][] hiddenStates = new double[seqLen][hiddenSize];
        double[][] outputs = new double[seqLen][outputSize];
        for (int t = 0; t < seqLen; t++) {
            // Update the hidden state
            if (t == 0) {
                for (int i = 0; i < hiddenSize; i++) {
                    double sum = 0.0;
                    for (int j = 0; j < inputSize; j++) {
                        sum += W_xh[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            } else {
                for (int i = 0; i < hiddenSize; i++) {
                    double sum = 0.0;
                    for (int j = 0; j < hiddenSize; j++) {
                        sum += W_hh[i][j] * hiddenStates[t - 1][j];
                    }
                    for (int j = 0; j < inputSize; j++) {
                        sum += W_xh[i][j] * inputs[t][j];
                    }
                    hiddenStates[t][i] = sigmoid(sum + b_h[i]);
                }
            }
            for (int i = 0; i < outputSize; i++) {
                double sum = 0.0;
                for (int j = 0; j < hiddenSize; j++) {
                    sum += W_hy[i][j] * hiddenStates[t][j];
                }
                outputs[t][i] = sum + b_y[i];
            }
        }
        return outputs;
    }
    private double sigmoid(double x) {
        return 1.0 / (1.0 + Math.exp(-x));
    }
    public static void main(String[] args) {
        int inputSize = 1;
        int hiddenSize = 64;
        int outputSize = 1;
        RNN rnn = new RNN(inputSize, hiddenSize, outputSize);
        double[][] inputs = { { 1.0 }, { 2.0 }, { 3.0 } };
        double[][] output = rnn.forward(inputs);
        for (double[] o : output) {
            System.out.println(Arrays.toString(o));
        }
    }
}
