/*
 * @lc app=leetcode.cn id=905 lang=java
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int n = nums.length;
        for(int i = 0, j = n - 1; i < j;) {
            while(i < n && (nums[i] & 1) == 0) i++;
            while(j >= 0 && (nums[j] & 1) == 1) j--;
            if(i < j) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        return nums;
    }
}
// @lc code=end

