import java.util.*;
import javax.lang.model.util.ElementScanner14;

import java.lang.Math.*; 
public class Binary_Exponentiation {

    public static long exp(long number, long pow) {
    if (pow == (long) 1)
      return (long)number;
    else if (pow == (long) 0)
      return (long) 1;
    else {
      {
        if (pow % (long) 2 == 0) {
            return exp(number, pow/2) * exp(number, pow/2);
        } else{
            return exp(number, (pow - 1) / 2) * exp(number, (pow - 1) / 2) * number;
        }
      }
    }

  }
    
    public static void main(String args[]){

        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int pow = scan.nextInt();

        System.out.println(exp((long) num, (long) pow));

    }
}

