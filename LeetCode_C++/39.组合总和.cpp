/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int start)
    {
        if(target <= 0)
        {
            if(target == 0)
                ans.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
};
// @lc code=end

