# 0216 组合总和-iii(Combination Sum III)

> 题目链接：[力扣](https://leetcode-cn.com/problems/combination-sum-iii/) | [LeetCode](https://leetcode.com/problems/combination-sum-iii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2597/1/)

## 题目

找出所有相加之和为 $n$ 的 $k$ 个数的组合。组合中只允许含有 $1 - 9$ 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1:

```plain
输入: k = 3, n = 7
输出: [[1,2,4]]
```

示例 2:

```plain
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
```

---

## 思路1

> ~~时间复杂度 $O(N)$，空间复杂度 $O(N)$~~

## 代码1

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    unordered_set<int> vis;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    void dfs(int k, int n, int start)
    {
        if(k == 0)
        {
            if(n == 0)
                ans.push_back(path);
            return;
        }

        for(int i = start; i <= 9; i++)
        {
            path.push_back(i);
            vis.insert(i);
            dfs(k - 1, n - i, i + 1);
            path.pop_back();
            vis.erase(i);
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
