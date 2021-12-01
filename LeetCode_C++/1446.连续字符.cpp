/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i < n; ) {
            int j = i;
            while(j < n && s[i] == s[j]) j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
// @lc code=end

