/*
 * @lc app=leetcode.cn id=1846 lang=java
 *
 * [1846] 减小和重新排列数组后的最大元素
 */

// @lc code=start
class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr[n - 1];
    }
}
// @lc code=end

