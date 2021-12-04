/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnts(26, 0);
        for(auto &c : magazine) cnts[c - 'a']++;
        for(auto &c : ransomNote) {
            int idx = c - 'a';
            cnts[idx]--;
            if(cnts[idx] < 0) return false;
        }
        return true;
    }
};
// @lc code=end

