/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        if(!a) return b;
        int sum = a ^ b, carry = (unsigned)(a & b) << 1;
        return getSum(carry, sum);
    }
};
// @lc code=end

