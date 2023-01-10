//Approach 
//        This code is a Java program that defines two functions for converting between decimal and binary number systems. The two functions are:
//
//        "DecToBinary(int n)" - This function takes an integer as input (n), which is a decimal number, and returns the binary equivalent of that number. 
//        It uses a while loop to repeatedly divide the decimal number by 2 and takes the remainder. 
//        Inside the while loop, it multiplies the remainder by 10 to the power of pow where pow is incremented each time and add the result to the biNum. 
//        This keeps on happening until the decimal number becomes 0 and the final value of biNum is the binary equivalent of the decimal number.
//
//        "binTodeci(int binNum)" - This function takes an integer as input (binNum), which is a binary number, and returns the decimal equivalent of that number.
//        It uses a while loop to repeatedly divide the binary number by 10 and takes the remainder. 
//        Inside the while loop, it multiplies the remainder by 2 to the power of pow where pow is incremented each time and add the result to the deci. 
//        This keeps on happening until the binary number becomes 0 and the final value of deci is the decimal equivalent of the binary number.
//
//        The main function of the code calls these two functions by passing two numbers num1 and num2 as input, num1 is a decimal number and num2 is a binary number.
//        It first calls the "DecToBinary(num1)" and prints the result, then calls the "binTodeci(num2)" and prints the result.
public class Conversion {
    //Function for converting Decimal value to Binary value
    public static int DecToBinary(int n){
       // int res=n;
        int pow=0;
        int biNum=0;
        while(n>0){
            int rem=n%2;
            biNum= biNum+ (rem * (int)Math.pow(10,pow));
            pow++;
            n=n/2;
        }
       return biNum;
    }
    //Function for converting Binary value to Decimal value
    public static int binTodeci(int binNum){
        int myNum=binNum;
        int pow=0;
        int deci=0;
        while(binNum>0){
            int n=binNum%10;
            deci=deci+(n * (int)Math.pow(2, pow));
            pow++;
            binNum=binNum/10;
        }
        return deci;
    }
    public static void main(String[] args) {
        int num1=5; // Decimal
        int num2=101; //Binary number
        System.out.println(DecToBinary(5));
        System.out.println(binTodeci(num2));

    }
}
