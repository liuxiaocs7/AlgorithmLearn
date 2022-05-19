/*
 * @lc app=leetcode.cn id=1049 lang=java
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int n = stones.length;
        int sum = 0;
        for(int stone : stones) sum += stone;
        int m = sum / 2;
        int[] f = new int[m + 1];

        for(int i = 0; i < n; i++) {
            int x = stones[i];
            for(int j = m; j >= x; j--) {
                f[j] = Math.max(f[j], f[j - x] + x);
            }
        }
        return sum - 2 * f[m];
    }
}
// @lc code=end

