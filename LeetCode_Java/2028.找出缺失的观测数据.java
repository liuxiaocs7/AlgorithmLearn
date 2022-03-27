/*
 * @lc app=leetcode.cn id=2028 lang=java
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int tot = (m + n) * mean;
        
        int sumRolls = 0, sumN = 0;
        for(int roll : rolls) {
            sumRolls += roll;
        }
        sumN = tot - sumRolls;
        if(sumN < n  || sumN > n * 6) {
            return new int[0];
        }

        int[] res = new int[n];
        for(int i = 0; i < n; i++) {
            res[i] = 1;
        }
        sumN -= n;
        for(int i = 0; i < n; i++) {
            while(sumN > 0 && res[i] < 6) {
                res[i]++;
                sumN--;
            }
        }
        return res;
    }
}
// @lc code=end

