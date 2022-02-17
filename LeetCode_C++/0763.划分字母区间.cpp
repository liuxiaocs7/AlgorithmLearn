/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> idx(26, 0);
        for(int i = 0; i < n; i++) idx[s[i] - 'a'] = i;

        vector<int> res;
        for(int i = 0; i < n; ) {
            int j = 0, maxRight = idx[s[i] - 'a'];
            while(j < n && j < maxRight) {
                j++;
                maxRight = max(maxRight, idx[s[j] - 'a']);
            }
            res.push_back(j - i + 1);
            i = j + 1;
        }
        return res;
    }
};
// @lc code=end

