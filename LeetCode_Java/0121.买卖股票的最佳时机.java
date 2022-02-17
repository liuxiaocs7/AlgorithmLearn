/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int t = 0;
        for(int i = 1; i < prices.length; i++) {
            t += prices[i] - prices[i - 1];
            res = Math.max(res, t);
            t = t < 0 ? 0 : t;
        }
        return res;
    }
}
// @lc code=end

