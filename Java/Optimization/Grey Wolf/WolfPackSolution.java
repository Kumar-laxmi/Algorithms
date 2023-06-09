package GreyWolfOptimization;

import java.util.List;

/**
 * WolfPackSolution contains information about solution to the particular problem, including best wolf and value progression
 * @author Matt
 *
 */
public class WolfPackSolution {
	private Wolf bestWolf;
	private List<Double> progression;
	
	public WolfPackSolution(Wolf bestWolf, List<Double> progression) {
		this.bestWolf = bestWolf;
		this.progression = progression;
	}
	
	public int iterationsPassed() {
		return progression.size();
	}
	
	public List<Double> getProgression(){
		return progression;
	}
	
	public Wolf getBestWolf() {
		return bestWolf;
	}
	
	public double solution() {
		return progression.get(iterationsPassed() - 1);
	}
	
	public String toString() {
		StringBuilder str = new StringBuilder();
		str.append("Best of each iteration\n");
		for(int i = 0; i < progression.size(); i++) {
			str.append((i + 1) + "#: " + progression.get(i) + "\n");
		}
		str.append("Best Wolf: " + bestWolf + "\n");
		str.append("Solution: " + solution() + "\n\n");
		return str.toString();
	}
}