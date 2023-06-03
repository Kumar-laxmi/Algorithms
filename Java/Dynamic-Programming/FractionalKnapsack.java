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

        //sorting array according to the profit / weight value

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

            //if the bag has capacity greater than the current weight
            //then add that weight in the bag
            if(capacity > weight){
                capacity -= weight;
                maxProfit += profit;
            } else {
                //if bag has less capacity than current weight
                //then add capacity / weight fraction of profit
                double fraction = (double) capacity / (double) weight;

                maxProfit += (profit * fraction);
                break;
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        //getting input for total number of items
        System.out.print("Enter number of items : ");
        int n = scan.nextInt();

        Pair[] items = new Pair[n];

        //getting input in pair for item profit and item weight for same item with space separated.

        System.out.println("Enter profit and weight in pair(space separated) : ");
        for(int i = 0 ; i < n ; i++){
            int profit = scan.nextInt();
            int weight = scan.nextInt();

            items[i] = new Pair(profit , weight);
        }

        System.out.print("Enter capacity of bag : ");

        int capacity = scan.nextInt();
        double maxProfit = getMaximumProfit(items , capacity);

        System.out.println(maxProfit);

        /*
            if number of items are 3
            such as
            60 10
            100 20
            120 30

            and capacity is 50

            Maximum profit will be 240.0 (60 + 100 + 120*(20(remaining capacity)/30(weight of current item)))
            iteration 1 :
                weight = 10 , profit = 60
                capacity = 50 - 10 = 40
                maxProfit = 0 + 60 = 60
            Iteration 2 :
                weight = 20 , profit = 100
                capacity = 40 - 20 = 20
                maxProfit = 60 + 100 = 160
            Iteration 3 :
                weight = 30 , profit = 120
                capacity = 20

                here , capacity < weight
                take fraction = capacity / weight = 2 / 3

                maxProfit = 160 + 120 * fraction = 160 + 80 = 240.0

         */
    }

}
