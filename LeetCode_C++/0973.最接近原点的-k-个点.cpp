/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
struct Point {
    int x, y;
    Point(int x_, int y_): x(x_), y(y_) {}
    bool operator < (const Point &p) const {
        return x * x + y * y < p.x * p.x + p.y * p.y;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> q;
        for(auto &point : points) {
            Point p(point[0], point[1]);
            if(q.size() < k) q.push(p);
            else {
                if(p < q.top()) {
                    q.pop();
                    q.push(p);
                }
            }
        }

        vector<vector<int>> res;
        while(!q.empty()) {
            Point t = q.top();
            q.pop();
            res.push_back({t.x, t.y});
        }
        return res;
    }
};
// @lc code=end

