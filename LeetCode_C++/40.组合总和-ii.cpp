/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    set<vector<int>> s;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        for(const auto it : s)
            ans.push_back(it);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int start)
    {
        if(target <= 0)
        {
            if(target == 0)
                s.insert(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

