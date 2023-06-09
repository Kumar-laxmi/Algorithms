package GreyWolfOptimization;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * 
 * @author Matt
 *
 */
public class WolfPack {
	private List<Wolf> pack;
	Wolf wAlpha = null;
	Wolf wBeta = null;
	Wolf wDelta = null;
	double wAlphaBest = Double.POSITIVE_INFINITY;
	double wBetaBest = Double.POSITIVE_INFINITY;
	double wDeltaBest = Double.POSITIVE_INFINITY;
	List<Double> lLimits, uLimits;
	
	/**
	 * Empty constructor
	 */
	public WolfPack() {
		
	}
	
	/**
	 * Initializes wolf pack
	 * @param N - number of wolves
	 * @param D - Number of dimensions of loaded function
	 * @param lLimits - lower bounds
	 * @param uLimits - upper bounds
	 */
	private void initializePack(int N, int D, List<Double> lLimits, List<Double> uLimits) {
		Random rand = new Random();
		pack = new ArrayList<Wolf>();
		this.lLimits = lLimits;
		this.uLimits = uLimits;
		
		for(int i=0;i<N;i++) {
			List<Double> pos = new ArrayList<Double>();
			for(int j=0;j<D;j++) {
				double P = rand.nextDouble() * (uLimits.get(j) - lLimits.get(j)) + lLimits.get(j);
				pos.add(P);
			}
			pack.add(new Wolf(pos));
		}
		wAlpha = null;
		wBeta = null;
		wDelta = null;
		wAlphaBest = Double.POSITIVE_INFINITY;
		wBetaBest = Double.POSITIVE_INFINITY;
		wDeltaBest = Double.POSITIVE_INFINITY;
		
	}
	private void resetWolfBests(Double val) {
		wAlphaBest = val;
		wBetaBest = val;
		wDeltaBest = val;
	}
	
	/**
	 * Assigns new three best wolves in a pack, default less than comparator
	 * @param f - Function loaded into function
	 */
	private void chooseLeadingWolves(Function f) {
		Comparator comp = new Comparator() {
			public boolean compare(double x, double y) { return x < y;}
		};
		
		chooseLeadingWolves(f, comp);
	}
	
	/**
	 * Assigns new three best wolves in a pack, according to provided comparator
	 * @param f - Function loaded into function
	 * @param comp - object Comparator that acts as a comparing mechanism 
	 */
	private void chooseLeadingWolves(Function f, Comparator comp) {

		for(Wolf w : pack) {
			double fVal = f.eval(w.getPos());
			if(comp.compare(fVal, wAlphaBest)) {
				wAlpha = w;
				wAlphaBest = fVal;
			}
		}
		for(Wolf w : pack) {
			double fVal = f.eval(w.getPos());
			if(comp.compare(fVal, wBetaBest) && w != wAlpha) {
				wBeta = w;
				wBetaBest = fVal;
			}
		}
		for(Wolf w : pack) {
			double fVal = f.eval(w.getPos());
			if(comp.compare(fVal, wDeltaBest) && w != wBeta && w != wAlpha) {
				wDelta = w;
				wDeltaBest = fVal;
			}
		}
		
		wAlpha = new Wolf(wAlpha);
		wBeta = new Wolf(wBeta);
		wDelta = new Wolf(wDelta);
	}
	
	/**
	 * Moves the given wolf in the pack, hunting behavior
	 * @param w - Wolf to be moved
	 * @param a - a coefficient, dictating how to move the wolf
	 */
	private void moveTheWolf(Wolf w, double a) {
		Random rand = new Random();
		for(int j=0;j<w.getPos().size();j++) {
			
			/**
			 * Move the wolves					
			 */
			double r1 = rand.nextDouble();
			double r2 = rand.nextDouble();
			
			double A1 = 2 * a * r1 - a;
			double C1 = 2 * r2;
			double DAlpha = Math.abs(C1 * wAlpha.posAtIndex(j) - w.posAtIndex(j));
			double X1 = wAlpha.posAtIndex(j) - A1 * DAlpha;
			
			r1 = rand.nextDouble();
			r2 = rand.nextDouble();
			
			double A2 = 2 * a * r1 - a;
			double C2 = 2 * r2;
			double DBeta = Math.abs(C2 * wBeta.posAtIndex(j) - w.posAtIndex(j));
			double X2 = wBeta.posAtIndex(j) - A2 * DBeta;
			
			r1 = rand.nextDouble();
			r2 = rand.nextDouble();
			
			double A3 = 2 * a * r1 - a;
			double C3 = 2 * r2;
			double DDelta = Math.abs(C3 * wDelta.posAtIndex(j) - w.posAtIndex(j));
			double X3 = wDelta.posAtIndex(j) - A3 * DDelta;
			
			w.setAtIndex(j, (X1 + X2 + X3) / 3);	
		}
	}
	
	/**
	 * Trims the wolf pack back into the limits
	 */
	private void trimToLimits() {
		for(int i=0;i<pack.size();i++) {
			Wolf w = pack.get(i);
			for(int j=0;j<w.getPos().size();j++) {
				if(w.posAtIndex(j) < lLimits.get(j)) {
					w.setAtIndex(j, lLimits.get(j));
				}
				if(w.posAtIndex(j) > uLimits.get(j)) {
					w.setAtIndex(j, uLimits.get(j));
				}
			}
		}
	}
	
	/**
	 * Finds a global minimum of a function on a given domain
	 * @param f - Function to be processed
	 * @param parameters - Specially prepared parameter class for wolf pack problems
	 * @return the best solution produced by the algorithm, packaged as special solution object
	 * @throws DimensionsUnmatchedException
	 */
	public WolfPackSolution findMinimum(Function f, WolfPackParameters parameters) throws DimensionsUnmatchedException {
		
		double MaxA = 2.0;
		List<Double> progression = new ArrayList<Double>();
		
		initializePack(parameters.getWolfCount(), parameters.getDimensions(), parameters.getLLimits(), parameters.getULimits());
		resetWolfBests(Double.POSITIVE_INFINITY);
		chooseLeadingWolves(f);
		
		int I = parameters.getIterations();
		for(int h=0;h<I;h++) {
			
			double a = MaxA - h * MaxA / (double) I;
			for(int i=0;i<pack.size();i++) {
				moveTheWolf(pack.get(i), a);
			}
			trimToLimits();
			resetWolfBests(Double.POSITIVE_INFINITY);
			chooseLeadingWolves(f);
			progression.add(f.eval(wAlpha.getPos()));
		}
		return new WolfPackSolution(wAlpha, progression);
	}
	
	/**
	 * Finds a global maximum of a function on a given domain
	 * @param f - Function to be processed
	 * @param parameters - Specially prepared parameter class for wolf pack problems
	 * @return the best solution produced by the algorithm, packaged as special solution object
	 * @throws DimensionsUnmatchedException
	 */
	public WolfPackSolution findMaximum(Function f, WolfPackParameters parameters) throws DimensionsUnmatchedException  {
		
		double MaxA = 2.0;
		List<Double> progression = new ArrayList<Double>();
		Comparator comp = new Comparator() {
			public boolean compare(double x, double y) { return x > y;}
		};
		
		initializePack(parameters.getWolfCount(), parameters.getDimensions(), parameters.getLLimits(), parameters.getULimits());
		resetWolfBests(Double.NEGATIVE_INFINITY);
		chooseLeadingWolves(f, comp);
		
		int I = parameters.getIterations();
		for(int h=0;h<I;h++) {
			
			double a = MaxA - h * MaxA / (double) I;
			for(int i=0;i<pack.size();i++) {
				moveTheWolf(pack.get(i), a);
			}
			trimToLimits();
			resetWolfBests(Double.NEGATIVE_INFINITY);
			chooseLeadingWolves(f, comp);
			progression.add(f.eval(wAlpha.getPos()));
		}
		return new WolfPackSolution(wAlpha, progression);
	}