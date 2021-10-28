/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool check(int a, int b) {
        unordered_multiset<char> s1, s2;
        for(auto &c : to_string(a)) s1.insert(c);
        for(auto &c : to_string(b)) s2.insert(c);
        return s1 == s2;
    }

    bool reorderedPowerOf2(int n) {
        for(int i = 1; i < 1e9; i *= 2) {
            if(check(i, n)) return true;
        }
        return false;
    }
};
// @lc code=end

