/*
 * @lc app=leetcode.cn id=62 lang=java
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) f[i][j] = 1;
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m][n];
    }
}
// @lc code=end

