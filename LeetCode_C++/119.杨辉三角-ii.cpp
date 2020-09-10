/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            for(int j = i; j > 0; j--)
                ans[j] = ans[j - 1] + ans[j];
        return ans;
    }
};
// @lc code=end

