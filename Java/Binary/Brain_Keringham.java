import java.io.*;

class Brain_Keringham{

    //Brian Kerningham's Algorithm in Java
    static int setBits(int n)
    {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    
    public static void main(String[] args) {
        System.out.println(setBits(15));
    }
}

