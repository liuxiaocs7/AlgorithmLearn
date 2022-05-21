/*
 * @lc app=leetcode.cn id=961 lang=java
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            if(i - 1 >= 0 && nums[i - 1] == t) return t;
            if(i - 2 >= 0 && nums[i - 2] == t) return t;
            if(i - 3 >= 0 && nums[i - 3] == t) return t;
        }
        return -1;
    }
}
// @lc code=end

