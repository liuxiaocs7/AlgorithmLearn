# 0079 单词搜索(Word Search)

> 题目链接：[力扣](https://leetcode-cn.com/problems/word-search/) | [LeetCode](https://leetcode.com/problems/word-search/) | [AcWing](3)

## 题目

---

## 思路1

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string &word, int u, int x, int y)
    {
        if(board[x][y] != word[u]) return false;
        if(u == word.size() - 1) return true;

        char t = board[x][y];
        board[x][y] = '.';  // 已访问过
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if(dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t;
        return false;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
