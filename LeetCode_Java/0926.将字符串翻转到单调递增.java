/*
 * @lc app=leetcode.cn id=926 lang=java
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int[] l = new int[n + 10], r = new int[n + 10];
        for(int i = 1; i <= n; i++) {
            l[i] = l[i - 1] + (s.charAt(i - 1) == '1' ? 1 : 0);
        }

        for(int i = n; i >= 1; i--) {
            r[i] = r[i + 1] + (s.charAt(i - 1) == '0' ? 1 : 0);
        }

        int res = Integer.MAX_VALUE;
        for(int i = 1; i <= n; i++) {
            res = Math.min(res, l[i - 1] + r[i + 1]);
        }
        return res;
    }
}
// @lc code=end

