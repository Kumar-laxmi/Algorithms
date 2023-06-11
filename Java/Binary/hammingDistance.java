import java.util.Scanner;
class hammingDistance {
    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter the value of X: ");
      int x = sc.nextInt();
      System.out.println("Enter the value of Y: ");
      int y= sc.nextInt();
      int count=0;
      int res = x ^ y;
      while(res>0){
        count+= res &1;
        res >>=1;
      }
      System.out.println("The result is: " + count);
    }
  }
  