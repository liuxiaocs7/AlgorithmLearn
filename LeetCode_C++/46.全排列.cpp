/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        vis = vector<bool>(nums.size());

        dfs(0, nums);
        return ans;
    }

    void dfs(int u, vector<int> &nums)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                path[u] = nums[i];
                vis[i] = true;
                dfs(u + 1, nums);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

