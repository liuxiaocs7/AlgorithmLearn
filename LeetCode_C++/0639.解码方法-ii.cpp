/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

// @lc code=start
class Solution {
public: 
    int numDecodings(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<long long> f(n + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 26; j++) {
                char a = s[i - 1];
                if(j <= 9) {
                    if(a == '*' || a == j + '0') f[i] += f[i - 1];
                } else if(i >= 2) { // 这样后面才有至少两位数
                    char b = s[i - 2];
                    int y = j / 10, x = j % 10; // y是十位，x是个位
                    // 因为*只能匹配1-9，因此后面要加上 &&x 和 &&y
                    if((b == y + '0' || b == '*' && y) && (a == x + '0' || a == '*' && x)) {
                        f[i] += f[i - 2];
                    }
                }
            }
            f[i] %= MOD;
        }
        return f[n];
    }
};
// @lc code=end

