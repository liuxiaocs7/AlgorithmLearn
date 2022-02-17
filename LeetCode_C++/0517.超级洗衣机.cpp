/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0, n = machines.size();
        for(auto x : machines) sum += x;
        if(sum % n) return -1;
        int avg = sum / n, left = 0, right = sum;
        int res = 0;
        for(int i = 0; i < n; i++) {
            right -= machines[i];
            if(i) left += machines[i - 1];
            int l = max(avg * i - left, 0);
            int r = max(avg * (n - i - 1) - right, 0);
            res = max(res, l + r);
        }
        return res;
    }
};
// @lc code=end

