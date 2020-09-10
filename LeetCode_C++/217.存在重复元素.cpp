/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(const auto &it : nums)
        {
            if(st.count(it))
                return true;
            else
                st.insert(it);
        }
        return false;
    }
};
// @lc code=end

