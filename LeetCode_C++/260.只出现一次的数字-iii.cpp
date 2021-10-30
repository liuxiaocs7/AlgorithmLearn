/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum ^= num;
        int k = -1;
        for(int i = 31; i >= 0 && k == -1; i--) {
            if((sum >> i) & 1) k = i;
        }
        vector<int> ans(2);
        for(int num : nums) {
            if((num >> k) & 1) ans[0] ^= num;
            else ans[1] ^= num;
        }
        return ans;
    }
};
// @lc code=end

