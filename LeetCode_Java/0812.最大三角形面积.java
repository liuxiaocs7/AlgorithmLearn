/*
 * @lc app=leetcode.cn id=812 lang=java
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
    public double largestTriangleArea(int[][] points) {
        int n = points.length;
        double res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int cur = cal(points[j][0] - points[i][0], points[j][1] - points[i][1], points[k][0] - points[i][0], points[k][1] - points[i][1]);
                    res = Math.max(res, Math.abs(cur / 2.0));
                }
            }
        }
        return res;
    }

    int cal(int a, int b, int c, int d) {
        return a * d - b * c;
    }
}
// @lc code=end

