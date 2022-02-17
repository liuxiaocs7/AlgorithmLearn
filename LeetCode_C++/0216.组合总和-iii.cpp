/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    unordered_set<int> vis;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    void dfs(int k, int n, int start)
    {
        if(k == 0)
        {
            if(n == 0)
                ans.push_back(path);
            return;
        }

        for(int i = start; i <= 9; i++)
        {
            path.push_back(i);
            vis.insert(i);
            dfs(k - 1, n - i, i + 1);
            path.pop_back();
            vis.erase(i);
        }
    }
};
// @lc code=end

