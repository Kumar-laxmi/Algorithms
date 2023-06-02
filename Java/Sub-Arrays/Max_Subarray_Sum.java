/*Name :  Yash Hibare
Github username : yashhibare7
Repositary name : Algorithms
*/
// Problem Statement: Java program to find Max subarray Sum
/*Example:
1] INPUT: int numbers[] = {2,4,6,8,10};
OUTPUT: max sum = 30 */
import java.util.*;

public class Max_Subarray_Sum {
    public static void maxSunarrSum(int numbers[]){
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        for(int i=0;i<numbers.length;i++){
            int start = i;
            for(int j=i;j<numbers.length;j++){
                int end =j;
                currSum=0;
                for(int k=start;k<=end;k++){
                    currSum += numbers[k];
                }
                System.out.println(currSum);
                if(maxSum<currSum){
                    maxSum=currSum;
                }
            }
        }
        System.out.println("max sum = "+ maxSum);
    }
    public static void main(String args[]){
        int numbers[]={2,4,6,8,10};
        maxSunarrSum(numbers);
    }
}
