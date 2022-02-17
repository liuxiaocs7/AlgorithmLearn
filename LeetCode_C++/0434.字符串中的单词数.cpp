/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(j < n && s[j] != ' ') j++;
            if(j - i >= 1) res++;
            i = j + 1;
        }
        return res;
    }
};
// @lc code=end

