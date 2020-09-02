/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp.count(target - nums[i]))
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }
        return {};
    }
};
// @lc code=end

