/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> q;
        int n = score.size();
        for(int i = 0; i < n; i++) q.push_back({score[i], i});
        sort(q.begin(), q.end(), greater<pair<int, int>>());
        vector<string> res(n);
        for(int i = 0; i < n; i++) {
            int k = q[i].second;
            if(i == 0) res[k] = "Gold Medal";
            else if(i == 1) res[k] = "Silver Medal";
            else if(i == 2) res[k] = "Bronze Medal";
            else res[k] = to_string(i + 1);
        }
        return res;
    }
};
// @lc code=end

