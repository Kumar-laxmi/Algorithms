import java.util.*;  
class Main{
    public static void main(String ...a){
    int first = 0, second = 1, result, i;
    Scanner sc= new Scanner(System.in);
    System.out.print("Enter number- ");  
    int n= sc.nextInt();  
    System.out.println("fibonacci series is: ");
    for (i = 0; i < n; i++)
    {
        if (i <= 1)
            result = i;
        else
        {
            result = first + second;
            first = second;
            second = result;
        }
    System.out.println(result+"\n");
    } 
  }
} 