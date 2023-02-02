/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int num : nums) {
            sum += num;
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};
// @lc code=end

