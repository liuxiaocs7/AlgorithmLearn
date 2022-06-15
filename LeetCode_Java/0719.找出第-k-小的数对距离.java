/*
 * @lc app=leetcode.cn id=719 lang=java
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = (int)1e6;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(nums, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    int check(int[] nums, int x) {
        int n = nums.length, res = 0;
        for(int i = 0, j = 1; i < n; i++) {
            while(j < n && nums[j] - nums[i] <= x) j++;
            res += j - i - 1;
        }
        return res;
    }
}
// @lc code=end

