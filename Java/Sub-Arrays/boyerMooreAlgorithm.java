//Code contributed by Raj kumar jaiswal(Github username: rajsrm2021)
// Boyer-Moore Majority Voting Algorithm 
/*This algorithm works on the fact that if an element occurs more than N/2 times, it means that the remaining elements other than this would definitely be less than N/2. So let us check the proceeding of the algorithm. */

/*Dry run for the above example: 
Given :
  arr[]=        1    1    1    1    2    3    5
 votes =0       1    2    3    4    3    2    1
 candidate = -1 1    1    1    1    1    1    1
 candidate = 1  after first traversal
                1    1    1    1    2    3    5
 count =0       1    2    3    4    4    4    4 
 candidate = 1  
 Hence count > 7/2 =3
 So 1 is the majority element.
 */

class boyerMooreAlgorithm {
    public static int majorityElement(int[] nums) {

        int ansIdx = 0;
        int count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[ansIdx] == nums[i]) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                ansIdx = i;
                count = 1;
            }
        }

        int count2 = 0;
        for (int num : nums) {
            if (nums[ansIdx] == num) {
                count2++;
            }
        }
        int ans = 0;
        if (count2 > (nums.length / 2)) {
            ans = nums[ansIdx];
        }

        return ans;

    }

    public static void main(String args[]) {

        int nums[] = { 1,1,1,1,2,3,5 };
        int ans = majorityElement(nums);
        System.out.println("majority Element is" + " = " + ans);

    }
}