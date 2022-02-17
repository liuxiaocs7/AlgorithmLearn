/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    void dfs(int n, int k, int start)
    {
        if(k == 0)
        {
            ans.push_back(path);
            return;
        }

        for(int i = start; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

