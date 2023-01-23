// Java program for implementation of Bisection Method
// for solving equations
class Bisection{
	static final float EPSILON = (float)0.01;

	// An example function whose solution is determined using
	// Bisection Method. The function is x^3 - x^2 + 2
	static double func(double x)
	{
		return x*x*x - x*x + 2;
	}

	// Prints root of func(x) with error of EPSILON
	static void bisection(double a, double b)
	{
		if (func(a) * func(b) >= 0)
		{
			System.out.println("You have not assumed"
						+ " right a and b");
			return;
		}

		double c = a;
		while ((b-a) >= EPSILON)
		{
			// Find middle point
			c = (a+b)/2;

			// Check if middle point is root
			if (func(c) == 0.0)
				break;

			// Decide the side to repeat the steps
			else if (func(c)*func(a) < 0)
				b = c;
			else
				a = c;
		}
				//prints value of c upto 4 decimal places
		System.out.printf("The value of root is : %.4f"
						,c);
	}

	// Driver program to test above function
	public static void main(String[] args)
	{
		// Initial values assumed
		double a =-200, b = 300;
		bisection(a, b);
	}
}
