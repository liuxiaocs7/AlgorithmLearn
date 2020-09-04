# 0062 不同路径(Unique Paths)

> 题目链接：[力扣](https://leetcode-cn.com/problems/unique-paths/description/) | [LeetCode](https://leetcode.com/problems/unique-paths/description/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2407/1/)

## 题目

一个机器人位于一个 $m * n$ 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

示例 1:

```plain
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
```

示例 2:

```plain
输入: m = 7, n = 3
输出: 28
```

提示:
$1 <= m, n <= 100$
题目数据保证答案小于等于 $2 * 10 ^ 9$。

---

## 思路1

DP分析：

- 状态表示：`dp[i][j]`表示从起点走到第`[i][j]`个格子的经过的路径条数
- 属性是**数量**
- 状态计算：

1. 最后一步向下走
2. 最后一步向右走

$$dp[i][j] = dp[i - 1][j] + dp[i][j - 1];$$

> 时间复杂度$O(N^2)$，空间复杂度$O(N^2)$

## 代码1

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};
```

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!i && !j) dp[i][j] = 1;  // 左上角
                if(i) dp[i][j] += dp[i - 1][j];  // 从上面过来
                if(j) dp[i][j] += dp[i][j - 1];  // 从左边过来
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
