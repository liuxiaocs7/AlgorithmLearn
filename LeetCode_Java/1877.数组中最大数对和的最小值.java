/*
 * @lc app=leetcode.cn id=1877 lang=java
 *
 * [1877] 数组中最大数对和的最小值
 */

// @lc code=start
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        for (int i = 0, j = nums.length - 1; i < j; i++, j--) {
            res = Math.max(res, nums[i] + nums[j]);
        }
        return res;
    }
}
// @lc code=end

