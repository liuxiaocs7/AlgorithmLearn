/*
 * @lc app=leetcode.cn id=566 lang=java
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length, n = mat[0].length;
        if(m * n != r * c) return mat;
        int[][] res = new int[r][c];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int t = i * n + j;
                res[t / c][t % c] = mat[i][j];
            }
        }
        return res;
    }
}
// @lc code=end

