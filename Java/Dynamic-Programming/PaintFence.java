import java.util.Scanner;

public class PaintFence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no of Post: ");
        int n = sc.nextInt();  // No of Post
        System.out.print("Enter no of colors: ");
        int k = sc.nextInt(); // No of Colors

        long same = k * 1;
        long diff = k * ( k - 1);
        long total = same + diff;

        for(int i=3;i<n;i++){
            same = diff * 1;
            diff = total * ( k - 1);
            total = same + diff;
        }

        System.out.println("No of Ways to paint fence: "+total);
    }
}
