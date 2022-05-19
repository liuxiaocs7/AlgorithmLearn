/*
 * @lc app=leetcode.cn id=744 lang=java
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0, r = letters.length;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(letters[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r == letters.length ? letters[0] : letters[r];
    }
}
// @lc code=end

