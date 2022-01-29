/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
typedef pair<int, int> PII;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<PII> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j]) {
                    res[i][j] = 0;
                    q.push({i, j});
                } else {
                    res[i][j] = -1;
                }
            }
        }

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newX = top.first + dx[i];
                int newY = top.second + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || res[newX][newY] != -1) continue;
                res[newX][newY] = res[top.first][top.second] + 1;
                q.push({newX, newY});
            }
        }
        return res;
    }
};
// @lc code=end

