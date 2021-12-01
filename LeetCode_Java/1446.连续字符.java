/*
 * @lc app=leetcode.cn id=1446 lang=java
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
    public int maxPower(String s) {
        int n = s.length(), res = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(j < n && s.charAt(i) == s.charAt(j)) j++;
            res = Math.max(res, j - i);
            i = j;
        }
        return res;
    }
}
// @lc code=end

