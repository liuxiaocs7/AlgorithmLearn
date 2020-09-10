# 1091 Shortest Path in Binary Matrix(计算在网格中从原点到特定点的最短路径长度)

> 题目链接：[力扣](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/) | [LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | [AcWing](3)

## 题目

在一个 $N × N$ 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。

一条从左上角到右下角、长度为 $k$ 的畅通路径，由满足下述条件的单元格 $C_1, C_2, ..., C_k$ 组成：

相邻单元格 $C_i$ 和 $C_{i+1}$ 在八个方向之一上连通（此时，$C_i 和 C_{i+1}$ 不同且共享边或角）
$C_1$ 位于 (0, 0)（即，值为 `grid[0][0]`）
$C_k$ 位于 (N-1, N-1)（即，值为 `grid[N-1][N-1]`）
如果 $C_i$ 位于 (r, c)，则 `grid[r][c]` 为空（即，`grid[r][c] == 0`）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

示例 1：

输入：[[0,1],[1,0]]
![示例1.1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/16/example1_1.png)
输出：2
![示例1.2](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/16/example1_2.png)

示例 2：

输入：[[0,0,0],[1,1,0],[1,1,0]]
![示例2.1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/16/example2_1.png)
输出：4
![示例2.2](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/16/example2_2.png)

提示：

1 <= grid.length == grid[0].length <= 100
grid[i][j] 为 0 或 1

---

## 思路1

【BFS】使用BFS从起点出发，遍历八个方向，记录遍历的**层数**即为最后结果。注意：起点和终点阻塞的时候无解。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
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
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
