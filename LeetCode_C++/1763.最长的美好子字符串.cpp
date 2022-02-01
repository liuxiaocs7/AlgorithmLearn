/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
class Solution {
    
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string res;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string t = s.substr(i, j - i + 1);
                bool exists = check(t);
                if(exists && res.size() < t.size()) res = t;
            }
        }
        return res;
    }

    bool check(string t) {
        unordered_set<char> cs;
        for(auto c : t) cs.insert(c);
        for(auto c : cs) {
            if(c >= 'A' && c <= 'Z' && !cs.count(c - 'A' + 'a')) return false;
            if(c >= 'a' && c <= 'z' && !cs.count(c - 'a' + 'A')) return false;
        }
        return true;
    }
};
// @lc code=end

