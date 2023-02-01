/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, int> mp;
        int idx = 0;
        for (auto c : key) {
            if (c == ' ' || mp.count(c)) continue;
            mp[c] = idx++;
        }
        string res;
        for (auto c : message) {
            if (c == ' ') res += ' ';
            else res += (mp[c] + 'a');
        }
        return res;
    }
};
// @lc code=end

