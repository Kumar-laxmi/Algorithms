/*Implementation of a XGBoost algorithm.
Author - Phalesh Kolpe*/

import java.util.ArrayList;
import java.util.List;

public class XGBoost {
    private List<Tree> trees;
    private double learningRate;
    private int numIterations;

    public XGBoost(double learningRate, int numIterations) {
        this.learningRate = learningRate;
        this.numIterations = numIterations;
        this.trees = new ArrayList<>();
    }

    public void train(List<double[]> features, double[] labels) {
        double[] residuals = labels.clone(); // Initialize residuals with labels
        for (int iteration = 0; iteration < numIterations; iteration++) {
            Tree tree = new Tree();
            tree.train(features, residuals);
            trees.add(tree);

            // Update residuals
            double[] predictions = tree.predict(features);
            for (int i = 0; i < residuals.length; i++) {
                residuals[i] = labels[i] - learningRate * predictions[i];
            }
        }
    }

    public double[] predict(List<double[]> features) {
        double[] predictions = new double[features.size()];
        for (Tree tree : trees) {
            double[] treePredictions = tree.predict(features);
            for (int i = 0; i < predictions.length; i++) {
                predictions[i] += learningRate * treePredictions[i];
            }
        }
        return predictions;
    }

    private static class Tree {
        private Node root;

        public void train(List<double[]> features, double[] residuals) {
            root = buildTree(features, residuals);
        }

            private Node buildTree(List<double[]> features, double[] residuals) {
        if (shouldStop(residuals)) {
            return createLeafNode(residuals);
        }

        Split split = findBestSplit(features, residuals);
        if (split == null) {
            return createLeafNode(residuals);
        }

        List<double[]> leftFeatures = new ArrayList<>();
        List<double[]> rightFeatures = new ArrayList<>();
        double[] leftResiduals = new double[features.size()];
        double[] rightResiduals = new double[features.size()];

        for (int i = 0; i < features.size(); i++) {
            double[] instance = features.get(i);
            if (isSplitSatisfied(instance, split)) {
                leftFeatures.add(instance);
                leftResiduals[i] = residuals[i];
            } else {
                rightFeatures.add(instance);
                rightResiduals[i] = residuals[i];
            }
        }

        Node node = new Node(split);
        node.leftChild = buildTree(leftFeatures, leftResiduals);
        node.rightChild = buildTree(rightFeatures, rightResiduals);

        return node;
    }



        private boolean shouldStop(double[] residuals) {
            // Stop if all residuals are zero or all are the same
            double firstResidual = residuals[0];
            for (double residual : residuals) {
                if (residual != firstResidual) {
                    return false;
                }
            }
            return true;
        }

        private Node createLeafNode(double[] residuals) {
            return new Node(residuals[0]);
        }

        private Split findBestSplit(List<double[]> features, double[] residuals) {
            Split bestSplit = null;
            double bestSplitScore = Double.MAX_VALUE;

            for (int i = 0; i < features.get(0).length; i++) {
                for (double threshold : findThresholds(features, i)) {
                    Split split = new Split(i, threshold);
                    double splitScore = calculateSplitScore(features, residuals, split);
                    if (splitScore < bestSplitScore) {
                        bestSplit = split;
                        bestSplitScore = splitScore;
                    }
                }
            }

            return bestSplit;
        }

        private double[] findThresholds(List<double[]> features, int featureIndex) {
            double[] thresholds = new double[features.size() - 1];
            List<double[]> sortedFeatures = new ArrayList<>(features);
            sortedFeatures.sort((a, b) -> Double.compare(a[featureIndex], b[featureIndex]));

            for (int i = 0; i < thresholds.length; i++) {
                thresholds[i] = (sortedFeatures.get(i)[featureIndex] + sortedFeatures.get(i + 1)[featureIndex]) / 2.0;
            }

            return thresholds;
        }

        private boolean isSplitSatisfied(double[] instance, Split split) {
            return instance[split.featureIndex] <= split.threshold;
        }

            private double calculateSplitScore(List<double[]> features, double[] residuals, Split split) {
        double[] leftResiduals = new double[features.size()];
        double[] rightResiduals = new double[features.size()];

        for (int i = 0; i < features.size(); i++) {
            double[] instance = features.get(i);
            if (isSplitSatisfied(instance, split)) {
                leftResiduals[i] = residuals[i];
            } else {
                rightResiduals[i] = residuals[i];
            }
        }

        double leftScore = calculateNodeScore(leftResiduals);
        double rightScore = calculateNodeScore(rightResiduals);
        return leftScore + rightScore;
    }


        private double calculateNodeScore(double[] residuals) {
            double sum = 0.0;
            for (double residual : residuals) {
                sum += Math.pow(residual, 2);
            }
            return sum;
        }

        public double[] predict(List<double[]> features) {
            double[] predictions = new double[features.size()];
            for (int i = 0; i < features.size(); i++) {
                double[] instance = features.get(i);
                predictions[i] = predictInstance(instance);
            }
            return predictions;
        }

        private double predictInstance(double[] instance) {
            Node node = root;
            while (!node.isLeafNode()) {
                if (isSplitSatisfied(instance, node.split)) {
                    node = node.leftChild;
                } else {
                    node = node.rightChild;
                }
            }
            return node.value;
        }
    }

    private static class Node {
        private Split split;
        private Node leftChild;
        private Node rightChild;
        private double value;

        public Node(Split split) {
            this.split = split;
        }

        public Node(double value) {
            this.value = value;
        }

        public boolean isLeafNode() {
            return leftChild == null && rightChild == null;
        }
    }

    private static class Split {
        private int featureIndex;
        private double threshold;

        public Split(int featureIndex, double threshold) {
            this.featureIndex = featureIndex;
            this.threshold = threshold;
        }
    }

    public static void main(String[] args) {
        // Sample input features and labels
        List<double[]> features = new ArrayList<>();
        features.add(new double[]{1.0, 2.0, 3.0});
        features.add(new double[]{4.0, 5.0, 6.0});
        features.add(new double[]{7.0, 8.0, 9.0});

        double[] labels = new double[]{10.0, 20.0, 30.0};

        // Create an instance of XGBoost and train the model
        XGBoost xgBoost = new XGBoost(0.1, 100);
        xgBoost.train(features, labels);

        // Sample input for prediction
        List<double[]> testFeatures = new ArrayList<>();
        testFeatures.add(new double[]{2.0, 3.0, 4.0});
        testFeatures.add(new double[]{5.0, 6.0, 7.0});

        // Perform predictions
        double[] predictions = xgBoost.predict(testFeatures);

        // Print the predictions
        System.out.println("Predictions:");
        for (double prediction : predictions) {
            System.out.println(prediction);
        }
    }

}


    

