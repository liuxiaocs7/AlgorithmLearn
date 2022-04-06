class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int a = cost[0], b = cost[1];
        for(int i = 2; i < n; i++) {
            int t = cost[i] + Math.min(a, b);
            a = b;
            b = t;
        }
        return Math.min(a, b);
    }
}