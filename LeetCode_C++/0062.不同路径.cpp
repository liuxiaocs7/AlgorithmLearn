/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!i && !j) dp[i][j] = 1;  // 左上角
                if(i) dp[i][j] += dp[i - 1][j];  // 从上面过来
                if(j) dp[i][j] += dp[i][j - 1];  // 从左边过来
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

