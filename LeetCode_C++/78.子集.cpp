/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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

        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();
        dfs(u + 1, nums);
    }
};
// @lc code=end

