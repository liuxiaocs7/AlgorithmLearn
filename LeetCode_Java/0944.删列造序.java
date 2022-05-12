/*
 * @lc app=leetcode.cn id=944 lang=java
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length, m = strs[0].length();
        int res = 0;
        // 遍历列
        for(int i = 0; i < m; i++) {
            char c = strs[0].charAt(i);
            for(int j = 1; j < n; j++) {
                if(strs[j].charAt(i) < c) {
                    res++;
                    break;
                }
                c = strs[j].charAt(i);
            }
        }
        return res;
    }
}
// @lc code=end

