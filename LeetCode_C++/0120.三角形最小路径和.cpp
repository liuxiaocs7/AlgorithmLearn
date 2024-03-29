/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
        return triangle[0][0];
    }
};
// @lc code=end

