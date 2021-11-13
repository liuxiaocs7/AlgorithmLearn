/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') cnt++;
        }
        return cnt == n || cnt == 0 || (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};
// @lc code=end

