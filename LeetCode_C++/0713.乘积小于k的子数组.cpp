/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), res = 0;
        int prod = 1;
        for(int i = 0, j = 0; i < n; i++) {
            prod *= nums[i];
            while(j < n && prod >= k) prod /= nums[j++];
            res += i - j + 1;
        }
        return res;
    }
};
// @lc code=end

