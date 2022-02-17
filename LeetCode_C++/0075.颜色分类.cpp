/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(const auto &it : nums)
            cnt[it]++;
        int k = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < cnt[i]; j++)
                nums[k++] = i;
    }
};
// @lc code=end

