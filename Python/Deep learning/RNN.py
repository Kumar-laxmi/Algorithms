import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))
class RNN:
    def __init__(self, intsize, hiddsize, outsize):
        self.intsize = intsize
        self.hiddsize = hiddsize
        self.outsize = outsize
        self.a1= np.random.randn(hiddsize, hiddsize)
        self.b1 = np.random.randn(intsize, hiddsize)
        self.c1 = np.random.randn(hiddsize, outsize)
    def forward(self, inputs):
        self.hidden_state = np.zeros((1, self.hiddsize))
        for x in inputs:
            self.hidden_state = np.tanh(np.dot(x, self.b1) + np.dot(self.hidden_state, self.W_hh))
        output = np.dot(self.hidden_state, self.c1)
        return output
intsize = 1
hiddsize = 32
outsize = 1
rnn = RNN(intsize, hiddsize, outsize)
inputs = np.array([[1], [2], [3]])
output = rnn.forward(inputs)
print(output)
