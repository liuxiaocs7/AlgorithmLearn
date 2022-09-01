/*
 * @lc app=leetcode.cn id=1475 lang=java
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] res = new int[n];
        Deque<Integer> d = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!d.isEmpty() && d.peekLast() > prices[i]) {
                d.pollLast();
            }
            res[i] = prices[i] - (d.isEmpty() ? 0 : d.peekLast());
            d.offerLast(prices[i]);
        }
        return res;
    }
}
// @lc code=end

