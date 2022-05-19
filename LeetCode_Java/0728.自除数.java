/*
 * @lc app=leetcode.cn id=728 lang=java
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new ArrayList<>();
        for(int i = left; i <= right; i++) {
            if(check(i)) res.add(i);
        }
        return res;
    }

    private boolean check(int x) {
        int t = x;
        while(x != 0) {
            int bit = x % 10;
            if(bit == 0 || t % bit != 0) return false;
            x /= 10;
        }
        return true;
    }
}
// @lc code=end

