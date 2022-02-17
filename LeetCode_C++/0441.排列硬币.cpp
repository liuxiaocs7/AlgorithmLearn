/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8.0 * n)) / 2;
    }
};
// @lc code=end

