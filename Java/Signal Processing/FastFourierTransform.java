public class FastFourierTransform {

    public static Complex[] fft(Complex[] x) {
        int N = x.length;

        // Base case
        if (N == 1) {
            return new Complex[]{x[0]};
        }

        // Split input array into even and odd parts
        Complex[] even = new Complex[N / 2];
        Complex[] odd = new Complex[N / 2];
        for (int i = 0; i < N / 2; i++) {
            even[i] = x[2 * i];
            odd[i] = x[2 * i + 1];
        }

        // Recursive calls for even and odd parts
        Complex[] evenResult = fft(even);
        Complex[] oddResult = fft(odd);

        // Combine the results
        Complex[] result = new Complex[N];
        for (int k = 0; k < N / 2; k++) {
            double kth = -2 * k * Math.PI / N;
            Complex w = new Complex(Math.cos(kth), Math.sin(kth));
            Complex oddTerm = w.multiply(oddResult[k]);
            result[k] = evenResult[k].add(oddTerm);
            result[k + N / 2] = evenResult[k].subtract(oddTerm);
        }

        return result;
    }

    public static void main(String[] args) {
        Complex[] x = {
                new Complex(1, 0),
                new Complex(2, 0),
                new Complex(3, 0),
                new Complex(4, 0)
        };

        Complex[] result = fft(x);

        System.out.println("FFT Result:");
        for (Complex c : result) {
            System.out.println(c);
        }
    }
}
