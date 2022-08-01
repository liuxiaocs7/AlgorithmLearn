/*
 * @lc app=leetcode.cn id=1374 lang=java
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
class Solution {
    public String generateTheString(int n) {
        StringBuilder sb = new StringBuilder();
        if (n % 2 == 0 && --n >= 0) sb.append('a');
        while (n-- > 0) sb.append('b');
        return sb.toString();
    }
}
// @lc code=end

