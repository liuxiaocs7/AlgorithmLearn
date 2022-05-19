/*
 * @lc app=leetcode.cn id=796 lang=java
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
    public boolean rotateString(String s, String goal) {
        int m = s.length(), n = goal.length();
        if(m != n) return false;

        for(int i = 0; i < m; i++) {
            int k = 0;
            while(k < n && s.charAt((i + k) % m) == goal.charAt(k)) k++;
            if(k == n) return true;
        }
        return false;
    }
}
// @lc code=end

