/*
 * @lc app=leetcode.cn id=942 lang=java
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
    public int[] diStringMatch(String s) {
        int n = s.length();
        int[] res = new int[n + 1];
        int l = 0, r = n;
        for(int i = 0; i < n; i++) {
            res[i] = s.charAt(i) == 'I' ? l++ : r--;
        }
        res[n] = l;
        return res;
    }
}
// @lc code=end

