package Java_practice;

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
