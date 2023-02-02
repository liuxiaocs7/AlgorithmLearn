/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        const int INF = 1e8;
        vector<vector<pair<int, int>>> g(n);
        for (auto &p : redEdges) g[p[0]].push_back({p[1], 0});
        for (auto &p : blueEdges) g[p[0]].push_back({p[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, INF));
        dist[0][0] = dist[0][1] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0}), q.push({0, 1});

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (auto &p : g[t.first]) {
                if (t.second != p.second && dist[p.first][p.second] > dist[t.first][t.second] + 1) {
                    dist[p.first][p.second] = dist[t.first][t.second] + 1;
                    q.push(p);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(min(dist[i][0], dist[i][1]));
            if (res[i] == INF) res[i] = -1;
        }
        return res;
    }
};
// @lc code=end

