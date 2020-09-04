# 0063 不同路径II(Unique Paths II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/unique-paths/description/) | [LeetCode](https://leetcode.com/problems/unique-paths/description/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2408/1/)

## 题目

一个机器人位于一个 $m x n$ 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

![problem](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

网格中的障碍物和空位置分别用 $1$ 和 $0$ 来表示。

说明：$m$ 和 $n$ 的值均不超过 $100$。

示例 1:

```plain
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

---

## 思路1

在62题的基础上增加一些**障碍**，不能走到有障碍的格子上，有障碍的格子相当于 `1` 需要额外增加一个能不能走的判断

DP分析：

- 状态表示：`dp[i][j]`表示从起点走到第`[i][j]`个格子的经过的路径条数
- 属性是**数量**
- 状态计算：

1. 最后一步向下走
2. 最后一步向右走

障碍物(原始数组中的1)默认对应的 `dp` 数组中的值为`0`(表示不可达，自然也无法通过其到达其他位置)，即使执行加法也无影响。

$$dp[i][j] = dp[i - 1][j] + dp[i][j - 1];$$

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N^2)$

## 代码1

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(!m) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!obstacleGrid[i][j])  // 不是障碍物
                {
                    if(!i && !j) dp[i][j] = 1;
                    if(i) dp[i][j] += dp[i - 1][j];
                    if(j) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
