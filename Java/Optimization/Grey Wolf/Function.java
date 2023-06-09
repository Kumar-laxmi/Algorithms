package GreyWolfOptimization;

import java.util.List;


public abstract class Function{
	protected int D;
	
	public Function(int D){
		this.D = D;
	}
	
	protected void checkDimensions(List<Double> args) throws DimensionsUnmatchedException {
		if(D != args.size())
			throw new DimensionsUnmatchedException();
	}
	
	public abstract double eval(List<Double> args) throws DimensionsUnmatchedException;
}