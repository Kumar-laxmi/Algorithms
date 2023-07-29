import numpy as np

def fft(signal):
    N = len(signal)  # Get the length of the signal
    if N <= 1:  # Base case: if the signal length is 1 or less, return the signal
        return signal
    even = fft(signal[0::2])  # Recursively compute the FFT of even-indexed samples
    odd = fft(signal[1::2])  # Recursively compute the FFT of odd-indexed samples
    factor = np.exp(-2j * np.pi * np.arange(N) / N)  # Compute the twiddle factors
    return np.concatenate([even + factor[:N // 2] * odd,  # Combine even and odd FFTs using twiddle factors
                           even + factor[N // 2:] * odd])

# Example usage
signal = np.array([0, 1, 2, 3, 4, 5, 6, 7])  # Create a sample signal
fft_result = fft(signal)  # Compute the FFT of the signal
print(fft_result)  # Print the FFT result
