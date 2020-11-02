/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for(const auto &it : nums2)
        {
            if(s.count(it))
            {
                ans.push_back(it);
                s.erase(s.find(it));
            }
        }
        return ans;
    }
};
// @lc code=end

