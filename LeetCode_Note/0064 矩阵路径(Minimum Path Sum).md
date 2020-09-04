# 0000 中文题目(英文题目)

> 题目链接：[力扣](https://leetcode-cn.com/problems/minimum-path-sum/) | [LeetCode](https://leetcode.com/problems/minimum-path-sum/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2409/1/)

## 题目

给定一个包含非负整数的 $m x n$ 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

```plain
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

---

## 思路1

DP分析：

- 状态表示：`dp[i][j]`表示从起点走到第`[i][j]`个格子的经过的最小值
- 属性是**最小值**(肯定不走重复的)
- 状态计算：

1. 最后一步向下走
2. 最后一步向右走

$$dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);$$

> 时间复杂度$O(N^2)$，空间复杂度$O(N^2)$

## 代码1

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!i && !j) dp[i][j] = grid[i][j];
                if(i) dp[i][j] = dp[i - 1][j] + grid[i][j];
                if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
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
