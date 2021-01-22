/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(ans.size() == 0 || ans.back()[1] < l) {
                ans.push_back({l, r});
            } else {
                ans.back()[1] = max(ans.back()[1], r);
            }
        }
        return ans;
    }
};
// @lc code=end

