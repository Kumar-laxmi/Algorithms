public class EqualSumPartition{
    public static boolean canPartition(int[] nums) {
        int sum=0;
        int N = nums.length;
        for(int i=0;i<N;i++){
            sum +=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        return e(N,nums,sum/2);
    }
    static boolean e(int N,int[] nums,int sum){
        boolean res=false;
        //res =e(N-1,nums,sum-nums[N-1]) || e(N-1,nums,sum);
        if (N == 0 && sum == 0) {
            return true;
        }
        if (N == 0 && sum != 0) {
            return false;
        }
        if(nums[N-1]>sum){
            res = e(N-1,nums,sum);
        }
        else{
            res = e(N-1,nums,sum-nums[N-1]) || e(N-1,nums,sum);
        }
        return res;
    }
    public static void main(String[] args){
        int[] nums = {1};
        System.out.println(""+canPartition(nums));
    }
}