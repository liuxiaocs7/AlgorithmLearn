/*
 * @lc app=leetcode.cn id=2028 lang=java
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length, cnt = m + n;
        int t = mean * cnt;
        for(int i : rolls) t -= i;
        if(t < n || t > 6 * n) return new int[0];
        int[] res = new int[n];
        Arrays.fill(res, t / n);
        t -= t / n * n;
        int k = 0;
        while(t-- > 0) {
            res[k++]++;
        }
        return res;
    }
}
// @lc code=end

