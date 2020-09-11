# 0077 组合(Combinations)

> 题目链接：[力扣](https://leetcode-cn.com/problems/combinations/) | [LeetCode](https://leetcode.com/problems/combinations/) | [AcWing](3)

## 题目

给定两个整数 $n$ 和 $k$，返回 $1 ... n$ 中所有可能的 $k$ 个数的组合。

示例:

```plain
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

---

## 思路1

> ~~时间复杂度 $O(N)$，空间复杂度 $O(N)$~~

## 代码1

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    void dfs(int n, int k, int start)
    {
        if(k == 0)
        {
            ans.push_back(path);
            return;
        }

        for(int i = start; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k - 1, i + 1);
            path.pop_back();
        }
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
