# 0120 三角形最小路径和(Triangle)

> 题目链接：[力扣](https://leetcode-cn.com/problems/triangle/) | [LeetCode](https://leetcode.com/problems/triangle/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2482/1/)

## 题目

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是下标与上一层结点下标相同或者等于上一层结点下标 +1 的两个结点。

例如，给定三角形：

```plain
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
```

说明：

如果你可以只使用 `O(n)` 的额外空间( `n` 为三角形的总行数)来解决这个问题，那么你的算法会很加分。

---

## 思路1

计算第 `i - 1` 层的时候只会用到第 `i`层的值，可以使用一个**滚动数组**进行计算。
先用一般的数组来写，最后改为**一维**的滚动数组。

> 时间复杂度 $O(N^2)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp = triangle[m - 1];
        for(int i = m - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};
```

---

## 思路2

DP分析：
状态表示：`f(i,j)`表示到达点`(i,j)`路径中值最小的路径的值  
属性：最小值  
状态计算：
$$f[i][j] = min(f[i+1][j]+w, f[i+1][j+1]+w)$$
注意需要从倒数第2行开始写入，避免数组越界。

> 时间复杂度 $O(N^2)$，空间复杂度 $O(1)$

## 代码2

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
        return triangle[0][0];
    }
};
```
