
import java.util.Arrays;
import java.util.Scanner;

class Pair{
    int profit , weight;

    public Pair(int profit , int weight){
        this.profit = profit;
        this.weight = weight;
    }
}

public class FractionalKnapsack {

    static double getMaximumProfit(Pair[] pairs , int capacity){
        double maxProfit = 0f;
        Arrays.sort(pairs, (o1, o2) -> {
            double val1 = (double) o1.profit / (double) o1.weight;
            double val2 = (double) o2.profit / (double) o2.weight;

            if(val1 < val2)
                return 1;
            else if (val1 == val2)
                return 0;
            return -1;
        });
        for(Pair p : pairs){
            int profit = p.profit;
            int weight = p.weight;
            System.out.println(profit + " " + weight);
            if(capacity > weight){
                capacity -= weight;
                maxProfit += profit;
            } else {
                double fraction = (double) capacity / (double) weight;

                maxProfit += (profit * fraction);
                break;
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Pair[] items = new Pair[n];

        for(int i = 0 ; i < n ; i++){
            int profit = scan.nextInt();
            int weight = scan.nextInt();

            items[i] = new Pair(profit , weight);
        }


        int capacity = 50;
        double maxProfit = getMaximumProfit(items , capacity);

        System.out.println(maxProfit);
    }

}
