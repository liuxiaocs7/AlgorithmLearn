/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int res = Integer.MIN_VALUE;
        int t = 0;
        for(int num : nums) {
            t += num;
            res = Math.max(res, t);
            t = t < 0 ? 0 : t;
        }
        return res;
    }
}
// @lc code=end

