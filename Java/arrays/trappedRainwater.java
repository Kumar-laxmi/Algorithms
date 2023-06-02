/*Name :  Yash Hibare
Github username : yashhibare7
Repositary name : Algorithms
*/
// Problem Statement: Java program to Given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water ite can trap after raining.
/*Example:
1] INPUT: int height[] = {4,2,0,6,3,2,5};
OUTPUT: 11 */
import java.util.*;

public class trappedRainwater {
    public static int tRainwater(int height[]){
        int n = height.length;
        //calculate left max boundry - array
        int leftMax[] = new int[n];
        leftMax[0] = height[0];
        for(int i=1;i<n;i++){
            leftMax[i] = Math.max(height[i], leftMax[i-1]);
        }

        //calculate right max boundry - array
        int rightMax[] = new int[n];
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            rightMax[i] = Math.max(height[i], rightMax[i+1]);
        }

        int trappedWater = 0;
        //loop
        for(int i=0; i<n; i++){
            int waterLevel = Math.min(leftMax[i], rightMax[i]);
            trappedWater += waterLevel - height[i];
        }

        return trappedWater;
    }

    public static void main(String args[]){
        int height[] = {4,2,0,6,3,2,5};
        System.out.println(tRainwater(height));
    }
}
