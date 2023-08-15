class Solution {
    public int majorityElement(int[] nums) {

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
}