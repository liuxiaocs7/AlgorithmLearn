# 0052 N皇后 II(N-Queens II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/n-queens-ii/) | [LeetCode](https://leetcode.com/problems/n-queens-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2397/1/)

## 题目

`n` 皇后问题研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

![题目](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)

上图为 `8` 皇后问题的一种解法。

给定一个整数 `n`，返回 `n` 皇后不同的解决方案的数量。

示例:

```plain
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
```

提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或 N-1 步，可进可退。（引用自 百度百科 - 皇后 ）

---

## 思路1

在51题的基础上不记录具体的方案，而是记录方案数，因此在找到一个满足的方案之后将计数器加1即可。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
    int N;
    vector<bool> col, dg, udg;
public:
    int totalNQueens(int n) {
        N = n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        return dfs(0);
    }

    int dfs(int u)
    {
        if(u == N) return 1;
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            if(!col[i] && !dg[u - i + N] && !udg[u + i])
            {
                col[i] = dg[u - i + N] = udg[u + i] = true;
                ans += dfs(u + 1);
                col[i] = dg[u - i + N] = udg[u + i] = false;
            }
        }
        return ans;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
