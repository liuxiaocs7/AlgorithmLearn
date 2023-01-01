/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mp;
        for (auto c : s) {
            if (++mp[c] == 2) return c;
        }
        return ' ';
    }
};
// @lc code=end

