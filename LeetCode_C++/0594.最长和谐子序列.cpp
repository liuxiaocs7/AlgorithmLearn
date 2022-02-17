/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &num: nums) mp[num]++;
        int res = 0;
        for(auto &num: nums) {
            if(mp[num - 1]) res = max(res, mp[num] + mp[num - 1]);
            if(mp[num + 1]) res = max(res, mp[num] + mp[num + 1]);
        }
        return res;
    }
};
// @lc code=end

