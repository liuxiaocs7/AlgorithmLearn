/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        for (int i = 0, j = 0; i < nums.length; i++) {
            if (j < i) return false;
            j = Math.max(j, i + nums[i]);
        }
        return true;
    }
}
// @lc code=end

