/*
 * @lc app=leetcode.cn id=371 lang=java
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
    public int getSum(int a, int b) {
        if(a == 0) return b;
        int sum = a ^ b, carry = (a & b) << 1;
        return getSum(carry, sum);
    }
}
// @lc code=end

