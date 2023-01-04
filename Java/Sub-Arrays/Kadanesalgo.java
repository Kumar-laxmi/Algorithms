

class Kadanesalgo {
    public static void main(String[] args) {
        int [] arr = {-2, -3, 4, -1, -2, 1, 5, -3};
        int answer = Kadanealgo(arr);
        System.out.println("The Maximum Continous Sub array is: "+answer);
    }

    public static int Kadanealgo(int[] arr) {
        int currSum = 0;
        int maxSum = 0;

        for (int i = 0; i < arr.length; i++) {
            currSum += arr[i];
            if (currSum > maxSum) {
                maxSum = currSum;
            }
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
}