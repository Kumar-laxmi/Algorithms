import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] localBestPosition;
    double localBestFitness;
    double fitness;

    Particle(double[][] bounds, int numVariables) {
        position = new double[numVariables];
        velocity = new double[numVariables];
        localBestPosition = new double[numVariables];
        localBestFitness = Double.POSITIVE_INFINITY;
        fitness = Double.POSITIVE_INFINITY;

        Random random = new Random();
        for (int i = 0; i < numVariables; i++) {
            position[i] = bounds[i][0] + random.nextDouble() * (bounds[i][1] - bounds[i][0]);
            velocity[i] = -1 + random.nextDouble() * 2;
            localBestPosition[i] = position[i];
        }
    }

    void evaluate(double[] globalBestPosition, ObjectiveFunction objectiveFunction) {
        fitness = objectiveFunction.evaluate(position);

        if (fitness < localBestFitness) {
            localBestFitness = fitness;
            System.arraycopy(position, 0, localBestPosition, 0, position.length);
        }
    }

    void updateVelocity(double[] globalBestPosition, double inertiaConstant, double cognitiveConstant, double socialConstant) {
        Random random = new Random();
        for (int i = 0; i < velocity.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();

            double cognitiveVelocity = cognitiveConstant * r1 * (localBestPosition[i] - position[i]);
            double socialVelocity = socialConstant * r2 * (globalBestPosition[i] - position[i]);
            velocity[i] = inertiaConstant * velocity[i] + cognitiveVelocity + socialVelocity;
        }
    }

    void updatePosition(double[][] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];

            if (position[i] > bounds[i][1]) {
                position[i] = bounds[i][1];
            }
            if (position[i] < bounds[i][0]) {
                position[i] = bounds[i][0];
            }
        }
    }
}

interface ObjectiveFunction {
    double evaluate(double[] position);
}

class ParticleSwarmOptimization {
    void optimize(ObjectiveFunction objectiveFunction, double[][] bounds, int numVariables, int particleSize, int iterations, double inertiaConstant, double cognitiveConstant, double socialConstant) {
        Particle[] swarmParticles = new Particle[particleSize];
        double[] globalBestPosition = new double[numVariables];
        double globalBestFitness = Double.POSITIVE_INFINITY;

        for (int i = 0; i < particleSize; i++) {
            swarmParticles[i] = new Particle(bounds, numVariables);
        }

        for (int iter = 0; iter < iterations; iter++) {
            for (Particle particle : swarmParticles) {
                particle.evaluate(globalBestPosition, objectiveFunction);

                if (particle.localBestFitness < globalBestFitness) {
                    globalBestFitness = particle.localBestFitness;
                    System.arraycopy(particle.localBestPosition, 0, globalBestPosition, 0, particle.localBestPosition.length);
                }

                particle.updateVelocity(globalBestPosition, inertiaConstant, cognitiveConstant, socialConstant);
                particle.updatePosition(bounds);
            }
        }

        System.out.println("RESULT:");
        System.out.print("Optimal Solution: (");
        for (int i = 0; i < globalBestPosition.length; i++) {
            System.out.print(globalBestPosition[i]);
            if (i != globalBestPosition.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println(")");
        System.out.println("Objective function value: " + globalBestFitness);
    }

    public static void main(String[] args) {
        double[][] bounds = { {-3000000.0, 3000000.0}, {-3000000.0, 3000000.0} };
        int numVariables = 2;
        int particleSize = 10;
        int iterations = 200;
        double inertiaConstant = 0.8;
        double cognitiveConstant = 1;
        double socialConstant = 2;

        ObjectiveFunction objectiveFunction = (position) -> {
            double x1 = position[0];
            double x2 = position[1];
            return 2 * x1 * x2 + x2 - x1 * x1 - 2 * x2 * x2;
        };

        ParticleSwarmOptimization pso = new ParticleSwarmOptimization();
        pso.optimize(objectiveFunction, bounds, numVariables, particleSize, iterations, inertiaConstant, cognitiveConstant, socialConstant);
    }
}
