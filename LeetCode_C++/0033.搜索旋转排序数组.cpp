/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;

        // 二分出 >= nums[0] 的分界点
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        // 结果在前半区间中，此时 r = l = 分界点
        if(target >= nums[0]) {
            // 重置l下一次二分
            l = 0;
        } else {
            l = l + 1;
            r = nums.size() - 1;
        }
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[r] == target ? r : -1;
    }
};
// @lc code=end

