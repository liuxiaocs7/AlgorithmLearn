/*
 * @lc app=leetcode.cn id=36 lang=java
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] row = new int[9];
        int[] col = new int[9];
        int[][] block = new int[3][3];

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int t = board[i][j] - '0' - 1;
                if(((row[i] >> t) & 1) == 1 || ((col[j] >> t) & 1) == 1 || ((block[i / 3][j / 3] >> t) & 1) == 1) {
                    return false;
                }
                row[i] |= 1 << t;
                col[j] |= 1 << t;
                block[i / 3][j / 3] |= 1 << t;
            }
        }
        return true;
    }
}
// @lc code=end

