class Solution {
    public int maxSubArray(int[] nums) {
        int res = Integer.MIN_VALUE, sum = 0;
        for (int num : nums) {
            sum += num;
            res = Math.max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
}