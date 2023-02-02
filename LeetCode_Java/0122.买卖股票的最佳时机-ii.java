/*
 * @lc app=leetcode.cn id=122 lang=java
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int res = 0, n = prices.length;
        for (int i = 1; i < n; i++) {
            int sub = prices[i] - prices[i - 1];
            if (sub > 0) res += sub;
        }
        return res;
    }
}
// @lc code=end

