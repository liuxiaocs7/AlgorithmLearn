/*
 * @lc app=leetcode.cn id=452 lang=java
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int res = 1, n = points.length;
        int l = points[0][0], r = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > r) {
                res++;
                l = points[i][0]; r = points[i][1];
            } else {
                r = Math.min(r, points[i][1]);
            }
        }

        return res;
    }
}
// @lc code=end

