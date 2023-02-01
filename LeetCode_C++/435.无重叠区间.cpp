/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1, r = intervals[0][1], n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= r) {
                r = intervals[i][1];
                res++;
            }
        }
        return n - res;
    }
};
// @lc code=end

