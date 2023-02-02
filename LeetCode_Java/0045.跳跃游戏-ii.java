/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        for (int i = 1, last = 0; i < n; i++) {
            while (last + nums[last] < i) last++;
            f[i] = f[last] + 1;
        }
        return f[n - 1];
    }
}
// @lc code=end

