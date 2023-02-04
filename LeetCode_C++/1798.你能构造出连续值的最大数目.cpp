/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

// @lc code=start
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for (auto x : coins) {
            if (x > sum + 1) return sum + 1;
            sum += x;
        }
        return sum + 1;
    }
};
// @lc code=end

