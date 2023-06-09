package GreyWolfOptimization;

import java.util.ArrayList;
import java.util.List;

public class Wolf {
	private List<Double> pos;
	
	public Wolf(List<Double> pos) {
		this.pos = new ArrayList<Double>();
		for(Double d : pos) {
			this.pos.add((double) d);
		}
	}
	
	public Wolf(Wolf w) {
		this.pos = new ArrayList<Double>();
		for(Double d : w.getPos()) {
			this.pos.add((double) d);
		}
	}
	
	public void setAtIndex(int i, double p) {
		pos.set(i, p);
	}
	
	public double posAtIndex(int i) {
		return pos.get(i);
	}
	
	public List<Double> getPos(){
		return pos;
	}
	
	public String toString() {
		return pos.toString();
	}
	
}