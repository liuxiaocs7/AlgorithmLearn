/*
 * @lc app=leetcode.cn id=693 lang=java
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
    public boolean hasAlternatingBits(int n) {
        boolean find = false;
        int prev = -1;
        for(int i = 30; i >= 0; i--) {
            int t = n >> i & 1;
            if(find && t != 1 - prev) return false;
            if(!find && t == 1) find = true;
            prev = t;
        }
        return true;
    }
}
// @lc code=end

