/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
                if(i && nums[i - 1] == nums[i] && !vis[i - 1]) continue;
                path[u] = nums[i];
                vis[i] = true;
                dfs(u + 1, nums);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

