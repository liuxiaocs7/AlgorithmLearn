package leetcodego

/*
 * @lc app=leetcode.cn id=36 lang=golang
 *
 * [36] 有效的数独
 */

// @lc code=start
func isValidSudoku(board [][]byte) bool {
	var row, col, block [9]int
	for i, r := range board {
		for j, c := range r {
			if c == '.' {
				continue
			}
			t := c - '0' - 1
			if ((row[i]>>t)&1) == 1 || ((col[j]>>t)&1) == 1 || ((block[i/3*3+j/3]>>t)&1) == 1 {
				return false
			}
			row[i] |= 1 << t
			col[j] |= 1 << t
			block[i/3*3+j/3] |= 1 << t
		}
	}
	return true
}

// @lc code=end
