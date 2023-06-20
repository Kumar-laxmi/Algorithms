import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AdaBoostClassifier {
    private int numClassifiers;
    private List<WeakClassifier> classifiers;
    private List<Double> alphas;
    private List<Double> classes;

    public AdaBoostClassifier(int numClassifiers) {
        this.numClassifiers = numClassifiers;
        this.classifiers = new ArrayList<>();
        this.alphas = new ArrayList<>();
        this.classes = new ArrayList<>();
    }

    public void fit(double[][] X, int[] y) {
        int nSamples = X.length;
        int nFeatures = X[0].length;

        classes.clear();

        // Find unique class labels
        for (int label : y) {
            double labelDouble = (double) label;
            if (!classes.contains(labelDouble)) {
                classes.add(labelDouble);
            }
        }

        double[] weights = new double[nSamples];
        for (int i = 0; i < nSamples; i++) {
            weights[i] = 1.0 / nSamples;
        }

        for (int t = 0; t < numClassifiers; t++) {
            WeakClassifier classifier = new WeakClassifier();

            // Find best weak classifier based on weighted error
            double bestError = Double.POSITIVE_INFINITY;

            for (int feature = 0; feature < nFeatures; feature++) {
                Map<Double, List<Integer>> uniqueValues = getUniqueValues(X, feature);
                for (double threshold : uniqueValues.keySet()) {
                    int[] prediction = new int[nSamples];
                    List<Integer> lessIndices = uniqueValues.get(threshold);
                    for (int index : lessIndices) {
                        prediction[index] = -1;
                    }

                    // Calculate weighted error
                    double weightedError = 0.0;
                    for (int i = 0; i < nSamples; i++) {
                        if (y[i] != prediction[i]) {
                            weightedError += weights[i];
                        }
                    }

                    if (weightedError < bestError) {
                        bestError = weightedError;
                        classifier.feature = feature;
                        classifier.threshold = threshold;
                        classifier.prediction = prediction.clone();
                    }
                }
            }

            // Calculate classifier weight (alpha)
            classifier.alpha = 0.5 * Math.log((1.0 - bestError) / (bestError + 1e-10));

            // Update weights
            double sumWeights = 0.0;
            for (int i = 0; i < nSamples; i++) {
                weights[i] *= Math.exp(-classifier.alpha * y[i] * classifier.prediction[i]);
                sumWeights += weights[i];
            }

            // Normalize weights
            for (int i = 0; i < nSamples; i++) {
                weights[i] /= sumWeights;
            }

            classifiers.add(classifier);
            alphas.add(classifier.alpha);
        }
    }

    public int[] predict(double[][] X) {
        int nSamples = X.length;
        int nClasses = classes.size();
        double[][] scores = new double[nSamples][nClasses];

        for (int t = 0; t < numClassifiers; t++) {
            WeakClassifier classifier = classifiers.get(t);
            double alpha = alphas.get(t);

            for (int i = 0; i < nSamples; i++) {
                double prediction = X[i][classifier.feature] < classifier.threshold ? -1 : 1;

                for (int j = 0; j < nClasses; j++) {
                    if (classes.get(j) == prediction) {
                        scores[i][j] += alpha;
                    }
                }
            }
        }

        int[] predictions = new int[nSamples];
        for (int i = 0; i < nSamples; i++) {
            double maxScore = Double.NEGATIVE_INFINITY;
            int maxIndex = -1;

            for (int j = 0; j < nClasses; j++) {
                if (scores[i][j] > maxScore) {
                    maxScore = scores[i][j];
                    maxIndex = j;
                }
            }

            predictions[i] = (int) Math.round(classes.get(maxIndex));
        }

        return predictions;
    }

    private Map<Double, List<Integer>> getUniqueValues(double[][] X, int feature) {
        Map<Double, List<Integer>> uniqueValues = new HashMap<>();

        for (int i = 0; i < X.length; i++) {
            double value = X[i][feature];
            if (!uniqueValues.containsKey(value)) {
                uniqueValues.put(value, new ArrayList<>());
            }
            uniqueValues.get(value).add(i);
        }

        return uniqueValues;
    }

    private static class WeakClassifier {
        public int feature;
        public double threshold;
        public int[] prediction;
        public double alpha;
    }

    public static void main(String[] args) {
        double[][] X = {{1, 2}, {2, 1}, {3, 4}, {4, 3}, {1, 3}, {4, 2}};
        int[] y = {0, 0, 1, 2, 1, 2};

        AdaBoostClassifier adaboost = new AdaBoostClassifier(3);
        adaboost.fit(X, y);

        double[][] XTest = {{1, 1}, {3, 3}};
        int[] yPred = adaboost.predict(XTest);

        System.out.print("Predictions: ");
        for (int label : yPred) {
            System.out.print(label + " ");
        }
    }
}
