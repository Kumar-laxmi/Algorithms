import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class KNN {

    private int k;
    private List<double[]> X_train;
    private List<Integer> y_train;

    public KNN(int k) {
        this.k = k;
        X_train = new ArrayList<>();
        y_train = new ArrayList<>();
    }

    public void fit(List<double[]> X, List<Integer> y) {
        X_train = X;
        y_train = y;
    }

    public List<Integer> predict(List<double[]> X) {
        List<Integer> y_pred = new ArrayList<>();
        for (double[] x : X) {
            int predictedLabel = _predict(x);
            y_pred.add(predictedLabel);
        }
        return y_pred;
    }

    private int _predict(double[] x) {
        double[] distances = new double[X_train.size()];
        for (int i = 0; i < X_train.size(); i++) {
            distances[i] = euclideanDistance(x, X_train.get(i));
        }

        int[] indices = argsort(distances);
        Map<Integer, Integer> labelCount = new HashMap<>();
        for (int i = 0; i < k; i++) {
            int label = y_train.get(indices[i]);
            labelCount.put(label, labelCount.getOrDefault(label, 0) + 1);
        }

        int mostCommonLabel = -1;
        int maxCount = -1;
        for (Map.Entry<Integer, Integer> entry : labelCount.entrySet()) {
            int label = entry.getKey();
            int count = entry.getValue();
            if (count > maxCount) {
                maxCount = count;
                mostCommonLabel = label;
            }
        }
        return mostCommonLabel;
    }

    private double euclideanDistance(double[] x1, double[] x2) {
        double sum = 0.0;
        for (int i = 0; i < x1.length; i++) {
            sum += Math.pow(x1[i] - x2[i], 2);
        }
        return Math.sqrt(sum);
    }

    private int[] argsort(double[] array) {
        int[] indices = new int[array.length];
        for (int i = 0; i < indices.length; i++) {
            indices[i] = i;
        }
        for (int i = 0; i < indices.length - 1; i++) {
            for (int j = i + 1; j < indices.length; j++) {
                if (array[indices[i]] > array[indices[j]]) {
                    int temp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = temp;
                }
            }
        }
        return indices;
    }

    public static void main(String[] args) {
        List<double[]> X_train = new ArrayList<>();
        X_train.add(new double[] { 1, 2 });
        X_train.add(new double[] { 1.5, 1.8 });
        X_train.add(new double[] { 5, 8 });
        X_train.add(new double[] { 8, 8 });
        X_train.add(new double[] { 1, 0.6 });
        X_train.add(new double[] { 9, 11 });

        List<Integer> y_train = new ArrayList<>();
        y_train.add(0);
        y_train.add(0);
        y_train.add(1);
        y_train.add(1);
        y_train.add(0);
        y_train.add(1);

        KNN knn = new KNN(3);
        knn.fit(X_train, y_train);

        List<double[]> X_test = new ArrayList<>();
        X_test.add(new double[] { 1, 2.5 });
        X_test.add(new double[] { 3, 4 });
        X_test.add(new double[] { 8, 9 });

        List<Integer> y_pred = knn.predict(X_test);

        System.out.println(y_pred);

    }
}