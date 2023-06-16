import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class grey_wolf {
    private static final int NUM_VARIABLES = 2;
    private static final int OPTIMIZATION_MODE = 1; // 1 for maximization, -1 for minimization
    private static final int PARTICLE_SIZE = 10;
    private static final int ITERATIONS = 200;
    private static final double INERTIA_CONSTANT = 0.8;
    private static final double COGNITIVE_CONSTANT = 1;
    private static final double SOCIAL_CONSTANT = 2;
    private static final double[][] BOUNDS = {{-3000000, 3000000}, {-3000000, 3000000}};

    private static Random random = new Random();

    private static double objectiveFunction(double[] position) {
        double x1 = position[0];
        double x2 = position[1];
        return 2 * x1 * x2 + x2 - x1 * x1 - 2 * x2 * x2;
    }

    private static class Particle {
        private double[] position;
        private double[] velocity;
        private double[] localBestPosition;
        private double localBestFitness;
        private double fitness;

        public Particle(double[][] bounds) {
            position = new double[NUM_VARIABLES];
            velocity = new double[NUM_VARIABLES];
            localBestPosition = new double[NUM_VARIABLES];
            localBestFitness = Double.POSITIVE_INFINITY;
            fitness = Double.POSITIVE_INFINITY;

            for (int i = 0; i < NUM_VARIABLES; i++) {
                position[i] = random.nextDouble() * (bounds[i][1] - bounds[i][0]) + bounds[i][0];
                velocity[i] = random.nextDouble() * 2 - 1;
            }
        }

        public void evaluate(double[] objectiveFunction) {
            fitness = objectiveFunction(position);
            if (OPTIMIZATION_MODE == -1) {
                if (fitness < localBestFitness) {
                    localBestPosition = position.clone();
                    localBestFitness = fitness;
                }
            } else if (OPTIMIZATION_MODE == 1) {
                if (fitness > localBestFitness) {
                    localBestPosition = position.clone();
                    localBestFitness = fitness;
                }
            }
        }

        public void updateVelocity(double[] globalBestPosition) {
            for (int i = 0; i < NUM_VARIABLES; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();

                double cognitiveVelocity = COGNITIVE_CONSTANT * r1 * (localBestPosition[i] - position[i]);
                double socialVelocity = SOCIAL_CONSTANT * r2 * (globalBestPosition[i] - position[i]);
                velocity[i] = INERTIA_CONSTANT * velocity[i] + cognitiveVelocity + socialVelocity;
            }
        }

        public void updatePosition(double[][] bounds) {
            for (int i = 0; i < NUM_VARIABLES; i++) {
                position[i] = position[i] + velocity[i];

                // Check and repair to satisfy the upper bounds
                if (position[i] > bounds[i][1]) {
                    position[i] = bounds[i][1];
                }
                // Check and repair to satisfy the lower bounds
                if (position[i] < bounds[i][0]) {
                    position[i] = bounds[i][0];
                }
            }
        }
    }

    public static void main(String[] args) {
        double initialFitness = OPTIMIZATION_MODE == -1 ? Double.POSITIVE_INFINITY : Double.NEGATIVE_INFINITY;
        double globalBestFitness = initialFitness;
        double[] globalBestPosition = new double[NUM_VARIABLES];
        List<Particle> swarmParticles = new ArrayList<>();

        for (int i = 0; i < PARTICLE_SIZE; i++) {
            swarmParticles.add(new Particle(BOUNDS));
        }

        for (int iter = 0; iter < ITERATIONS; iter++) {
            for (Particle particle : swarmParticles) {
              

                if (OPTIMIZATION_MODE == -1) {
                    if (particle.fitness < globalBestFitness) {
                        globalBestPosition = particle.position.clone();
                        globalBestFitness = particle.fitness;
                    }
                } else if (OPTIMIZATION_MODE == 1) {
                    if (particle.fitness > globalBestFitness) {
                        globalBestPosition = particle.position.clone();
                        globalBestFitness = particle.fitness;
                    }
                }

                particle.updateVelocity(globalBestPosition);
                particle.updatePosition(BOUNDS);
            }
        }

        System.out.println("RESULT:");
        System.out.println("Optimal Solution: " + java.util.Arrays.toString(globalBestPosition));
        System.out.println("Objective function value: " + globalBestFitness);
    }
}
