/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int cnt = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] != '-') {
                res.push_back(toupper(s[i]));
                cnt++;
                if(cnt % k == 0) res.push_back('-');
            }
        }
        if(res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

