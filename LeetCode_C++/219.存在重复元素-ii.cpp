/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        bool ans = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!mp.count(nums[i]))
            {
                mp[nums[i]] = i;
            }
            else
            {
                if(i - mp[nums[i]] <= k)
                    ans = true;
                mp[nums[i]] = i;  // 保证最小
            }
        }
        return ans;
    }
};
// @lc code=end

