/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> S(nums1.begin(), nums1.end());
        vector<int> ans;

        for(const auto &it : nums2)
        {
            if(S.count(it))
            {
                ans.push_back(it);
                S.erase(it);
            }
        }
        return ans;
    }
};
// @lc code=end

