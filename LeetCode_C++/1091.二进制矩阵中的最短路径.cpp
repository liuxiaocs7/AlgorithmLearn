/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n) return -1;
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(n));
        queue<pair<int, int>> q;
        int d[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

        if(!grid[0][0] && !grid[n - 1][n - 1]) q.push({0, 0});
        vis[0][0] = true;

        while(!q.empty())
        {
            int sz = q.size();
            ans++;

            for(int i = 0; i < sz; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n - 1 && y == n - 1)
                    return ans;

                for(int j = 0; j < 8; j++)
                {
                    int dx = x + d[j][0];
                    int dy = y + d[j][1];

                    if(dx >= 0 && dx <= n - 1 && dy >= 0 && dy <= n - 1 && !vis[dx][dy] && !grid[dx][dy])
                    {
                        q.push({dx, dy});
                        vis[dx][dy] = true;
                    }
                        
                }
            }
        }
        return -1;
    }
};
// @lc code=end

