/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        for (; i < n && j < m; j++) {
            if (s[i] == t[j]) i++;
        }
        return i == n;
    }
};
// @lc code=end

