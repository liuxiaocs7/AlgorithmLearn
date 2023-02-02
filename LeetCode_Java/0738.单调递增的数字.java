/*
 * @lc app=leetcode.cn id=738 lang=java
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
    public int monotoneIncreasingDigits(int n) {
        char[] arr = ("" + n).toCharArray();
        int max = -1, idx = -1;
        for (int i = 0; i < arr.length - 1; i++) {
            if (max < arr[i]) {
                max = arr[i];
                idx = i;
            }

            if (arr[i] > arr[i + 1]) {
                arr[idx]--;
                for (int j = idx + 1; j < arr.length; j++) {
                    arr[j] = '9';
                }
                break;
            }
        }
        return Integer.parseInt(new String(arr));
    }
}
// @lc code=end

