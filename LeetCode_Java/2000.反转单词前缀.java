/*
 * @lc app=leetcode.cn id=2000 lang=java
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
    public String reversePrefix(String word, char ch) {
        int n = word.length(), idx = -1;
        char[] wordArray = word.toCharArray();
        for(int i = 0; i < word.length(); i++) {
            if(word.charAt(i) == ch) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return word;
        for(int i = 0, j = idx; i < j; i++, j--) {
            char t = wordArray[i];
            wordArray[i] = wordArray[j];
            wordArray[j] = t;
        }
        return new String(wordArray);
    }
}
// @lc code=end

