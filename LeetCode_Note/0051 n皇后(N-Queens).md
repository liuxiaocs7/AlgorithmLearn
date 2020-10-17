# 0051 n皇后(N-Queens)

> 题目链接：[力扣](https://leetcode-cn.com/problems/n-queens/) | [LeetCode](https://leetcode.com/problems/n-queens/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2396/1/)

## 题目

`n` 皇后问题研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

![题目](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)

上图为 `8` 皇后问题的一种解法。

给定一个整数 `n`，返回所有不同的 `n` 皇后问题的解决方案。

每一种解法包含一个明确的 `n` 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

---

## 思路1

【DFS】按行 `y` 遍历，其中 `col[x]` ,`dg[y - x + n]` , `udg[y + x]` 分别记录的是该位置的列，斜，反斜线上是否已经存在过，若均不存在，填入皇后，并递归到下一行.

> 时间复杂度 $O(N!)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
    int N;
    vector<bool> col, dg, udg;
    vector<vector<string>> ans;
    vector<string> path;
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n, string(n, '.'));
        dfs(0);
        return ans;
    }

    void dfs(int u)
    {
        if(u == N)
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < N; i++)
        {
            if(!col[i] && !dg[u - i + N] && !udg[u + i])
            {
                col[i] = dg[u - i + N] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[u - i + N] = udg[u + i] = false;
            }
        }
    }
};
```

```java
class Solution {
    private int N = 20;
    boolean[] col;
    boolean[] dg;
    boolean[] udg;
    List<List<String>> ans = new ArrayList<List<String>>();
    char[][] g;

    void dfs(int u) {
        if(u == N) {
            List<String> path = new ArrayList<>();
            for(int i = 0; i < N; i++) {
                String t = "";
                for(int j = 0; j < N; j++)
                    t += g[i][j];
                path.add(t);
            }
            ans.add(path);
            return;
        }

        for(int i = 0; i < N; i++) {
            if(!col[i] && !dg[u + i] && !udg[u - i + N]) {
                col[i] = dg[u + i] = udg[u - i + N] = true;
                g[u][i] = 'Q';
                dfs(u + 1);
                col[i] = dg[u + i] = udg[u - i + N] = false;
                g[u][i] = '.';
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        N = n;
        g = new char[n][n];
        col = new boolean[n];
        dg = new boolean[n * 2];
        udg = new boolean[n * 2];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = '.';

        dfs(0);
        return ans;
    }
}
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
