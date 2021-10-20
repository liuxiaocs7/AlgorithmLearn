/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int tot = 0, minV = INT_MAX, n = nums.size();
        for(auto num: nums) {
            tot += num;
            minV = min(minV, num);
        }
        return tot - minV * n;
    }
};
// @lc code=end

