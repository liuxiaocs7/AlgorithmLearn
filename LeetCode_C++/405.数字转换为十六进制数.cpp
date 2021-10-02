/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        string res;
        for(int i = 0; i < 8; i++) {
            int t = 0;
            for(int j = 3; j >= 0; j--) {
                t = t * 2 + ((num >> i * 4 + j) & 1);
            }
            res += transfer(t);
        }

        while(res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }

    char transfer(int num) {
        if(num < 10) return num + '0';
        else return num - 10 + 'a';
    }
};
// @lc code=end

