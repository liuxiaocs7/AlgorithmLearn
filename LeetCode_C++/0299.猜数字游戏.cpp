/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int na = 0, nb = 0, n = secret.size();
        vector<int> fa(10), fb(10);
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) na++;
            else {
                fa[secret[i] - '0']++;
                fb[guess[i] - '0']++;
            }
        }
        for(int i = 0; i <= 9; i++) {
            nb += min(fa[i], fb[i]);
        }
        return to_string(na) + "A" + to_string(nb) + "B";
    }
};
// @lc code=end

