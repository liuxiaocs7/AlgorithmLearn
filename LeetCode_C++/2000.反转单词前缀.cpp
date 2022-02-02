/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch) {
                idx = i;
                break;
            }
        }
        if(idx == 0) return word;
        for(int i = 0, j = idx; i < j; i++, j--) swap(word[i], word[j]);
        return word;
    }
};
// @lc code=end

