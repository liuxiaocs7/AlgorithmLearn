/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR = m, minC = n;
        for(auto &op: ops) {
            minR = min(minR, op[0]);
            minC = min(minC, op[1]);
        }
        return minR * minC;
    }
};
// @lc code=end

