/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};
// @lc code=end

