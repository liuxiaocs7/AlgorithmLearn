/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        if (n <= 2) return n;
        int res = 2;
        for (int i = 1; i + 1 < n; i++) {
            int a = nums[i - 1], b = nums[i], c = nums[i + 1];
            if (b > a && b > c || b < a && b < c) res++;
        }
        return res;
    }
};
// @lc code=end

