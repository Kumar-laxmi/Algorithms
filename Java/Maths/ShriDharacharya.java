import java.util.Scanner;
import java.lang.Math;
public class ShriDharacharya {
    public static void ShriDharacharyaFormulae(double a, double b, double c){
        double compValue = (Math.pow(b,2) - 4*a*c);
        double val1 = -b/(2*a);
        double val2 = Math.pow(compValue,.5)/(2*a);
        if(compValue>=0){
            System.out.println((val1+val2) + "and " + (val1-val2));
        }
        else{
            System.out.println("Imaginary roots");
        }
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        ShriDharacharyaFormulae(a,b,c);
        scan.close();
    }
}
