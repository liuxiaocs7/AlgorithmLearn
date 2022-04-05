/*
 * @lc app=leetcode.cn id=762 lang=java
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {

    static boolean[] hash = new boolean[40];
    static {
        int[] nums = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for(int x : nums) hash[x] = true;
    }

    public int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++) {
            int x = i, cnt = 0;
            while(x != 0 && ++cnt >= 0) x -= (x & -x);
            if(hash[cnt]) res++;
        }
        return res;
    }
}
// @lc code=end

