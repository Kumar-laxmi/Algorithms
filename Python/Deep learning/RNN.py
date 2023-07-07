import numpy as np

# Define the sigmoid activation function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Define the RNN class
class RNN:
    def __init__(self, input_size, hidden_size, output_size):
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.output_size = output_size

        # Initialize weights
        self.W_hh = np.random.randn(hidden_size, hidden_size)
        self.W_xh = np.random.randn(input_size, hidden_size)
        self.W_hy = np.random.randn(hidden_size, output_size)

    def forward(self, inputs):
        self.hidden_state = np.zeros((1, self.hidden_size))

        # Iterate over each input in the sequence
        for x in inputs:
            # Update the hidden state
            self.hidden_state = np.tanh(np.dot(x, self.W_xh) + np.dot(self.hidden_state, self.W_hh))

        # Compute the output
        output = np.dot(self.hidden_state, self.W_hy)
        return output

# Example usage
input_size = 1
hidden_size = 64
output_size = 1

# Create an RNN instance
rnn = RNN(input_size, hidden_size, output_size)

# Define the input sequence
inputs = np.array([[1], [2], [3]])

# Forward pass
output = rnn.forward(inputs)
print(output)
