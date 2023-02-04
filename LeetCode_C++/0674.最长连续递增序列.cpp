/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
            res = max(res, f[i]);
        }
        return res;
    }
};
// @lc code=end

