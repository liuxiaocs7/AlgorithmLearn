/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
// @lc code=end

