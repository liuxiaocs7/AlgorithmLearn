/*
 * @lc app=leetcode.cn id=724 lang=java
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        
        int t = 0;
        for(int i = 0; i < nums.length; i++) {
            if (t * 2 == sum - nums[i]) return i;
            t += nums[i];
        }
        return -1;
    }
}
// @lc code=end

