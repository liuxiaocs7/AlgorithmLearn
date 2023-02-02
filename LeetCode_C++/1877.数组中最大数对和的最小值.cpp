/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 *
 * [1877] 数组中最大数对和的最小值
 */

// @lc code=start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            res = max(res, nums[i] + nums[j]);
        }
        return res;
    }
};
// @lc code=end

