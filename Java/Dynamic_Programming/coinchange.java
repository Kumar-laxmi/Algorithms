import java.util.Scanner;

public class coinchange{
    public static int [][]dp= new int[1001][1001]; // since constraint is given of 1000, we take dp[1001][1001]
    public static int numberOfWays(int []coins, int n, int sum){
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<sum+1; j++){
                if(i == 0){ // if coin's value is 0, we can't form the sum
                    dp[i][j] = 0;
                }
                if(j == 0){ // if sum is 0, there will always be one way to form sum 0
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(coins[i-1]<=j){// if the coin's value is less than the given sum
                // there will be two possibilities whether to take it or leave it
                // Total       // we pick it so sum got reduced and we will stay on the same index         
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                                                    // we didn't pick it
                }
                else{
                    dp[i][j] = dp[i-1][j]; // if we didn't pick it then the sum remains same and we will move to the next index
                }
            }
        }
        return dp[n][sum]; // return ans

    }
    public static void main(String args[]){
        int n, sum;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sum = sc.nextInt();
        int []coins = new int[n];
        for(int i = 0; i<n; i++){
            coins[i] = sc.nextInt();
        }
        // coinchange ref = new coinchange();
        System.out.println(numberOfWays(coins,n,sum));
    }
}