/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(const auto &it : nums) {
            sum += it;
        }

        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(leftSum == sum - leftSum - nums[i]) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

