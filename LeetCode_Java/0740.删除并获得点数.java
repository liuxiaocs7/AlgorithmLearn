/*
 * @lc app=leetcode.cn id=740 lang=java
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
    int[] cnts = new int[10010];

    public int deleteAndEarn(int[] nums) {
        int n = nums.length;
        int max = 0;
        for(int num : nums) {
            cnts[num]++;
            max = Math.max(max, num);
        }

        int[][] f = new int[max + 1][2];
        for(int i = 1; i <= max; i++) {
            f[i][0] = Math.max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + i * cnts[i];
        }
        return Math.max(f[max][0], f[max][1]);
    }
}
// @lc code=end

