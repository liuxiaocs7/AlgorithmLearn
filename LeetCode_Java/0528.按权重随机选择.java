/*
 * @lc app=leetcode.cn id=528 lang=java
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {

    int[] sum;
    int max = 0, n = 0;

    public Solution(int[] w) {
        n = w.length;
        sum = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + w[i - 1];
        }
        max = sum[n];
    }
    
    public int pickIndex() {
        Random random = new Random();
        int pick = random.nextInt(max);
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if(sum[mid] <= pick) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

// @lc code=end

