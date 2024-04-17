/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> right(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            right[s[i] - 'a'] = i;
        }

        vector<int> res;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, right[s[i] - 'a']);
            if (i == r) {
                res.push_back(r - l + 1);
                l = r = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

