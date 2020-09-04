# 0070 爬楼梯(Climbing Stairs)

> 题目链接：[力扣](https://leetcode-cn.com/problems/climbing-stairs/description/) | [LeetCode](https://leetcode.com/problems/climbing-stairs/description/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2415/1/)

## 题目

假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 `n` 是一个正整数。

示例 1：

```plain
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

示例 2：

```plain
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```

---

## 思路1

DP分析：

- 状态表示：`dp[i]`表示上到第`i`级楼梯的方法数目
- 属性是**最大值**
- 状态计算：要么走两步上来，要么走一步上来

注意边界情况的处理，即初始值 `dp[1]` 以及 `dp[2]`。
最后的结果即为 `dp[n]` 表示上到第 `n` 级楼梯的方法数目

$$dp[i] = dp[i - 1] + dp[i - 2]$$

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 2, 0);
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
