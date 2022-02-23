/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = -1, j = n;
        while(i < j) {
            while(i < j && !check(s[++i]));
            while(i < j && !check(s[--j]));
            if(i < j) swap(s[i], s[j]);
        }
        return s;
    }

    bool check(char c) {
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
};
// @lc code=end

