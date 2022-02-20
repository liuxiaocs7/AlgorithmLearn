/*
 * @lc app=leetcode.cn id=717 lang=java
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        int i = 0;
        for(; i < n - 1; ) {
            if(bits[i] == 0) i += 1;
            else i += 2;
        }
        return i == n - 1;
    }
}
// @lc code=end

