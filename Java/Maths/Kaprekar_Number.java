package Java.Maths;

public class Kaprekar_Number{
    
    static boolean kaprekar_num(int num)
    {
        if(num==1)
    {
        return true;
    }

    int squre=num*num;   //Here we calculate squre of the given number
    
    int number=squre;
    
    int digits=0;  //Initialy we assign 0 to this variable as we calculate digits we just increment it by one

    while(squre!=0)  //In this while loop we just calculate digits 
    {
        digits++;

        squre=squre/10;
    }

    for(int i=1;i<digits;i++)
    {
        int power_of_10=(int)Math.pow(10,i);

        if(power_of_10==num)  //This means the power of nuber is like 10 ,100 and so on 
             continue;        //this are not kaprekar numbers
        

        //Now actual part begins

        //int num1 = number/power_of_10 ;
        //int num2 = number%power_of_10;

        int summation= number/power_of_10 + number%power_of_10;

        if(summation==num)
        {
            return true;
        }
    }

    return false;
    }
     
    // Driver method
    public static void main (String[] args)
    {
        if(kaprekar_num(45))
        {
            System.out.println(" 45 This number is Kaprekar Number");
        }
        else
        {
             System.out.println("This number is Kaprekar Number");

        }
    }
}

//**************************** */

// Case 1 : Enter Number 45 

// output : This is kaprekar number

// Case 2 : Enter Number 128

// output : This is Not Kaprekar Number

//************************** */