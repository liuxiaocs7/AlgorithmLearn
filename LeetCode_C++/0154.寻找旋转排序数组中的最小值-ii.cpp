/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r && nums[r] == nums[0]) r--;
        if(nums[l] <= nums[r]) return nums[l];
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[r];
    }
};
// @lc code=end

