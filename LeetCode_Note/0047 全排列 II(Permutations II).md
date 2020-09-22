# 0047 全排列 II(Permutations II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/permutations-ii/) | [LeetCode](https://leetcode.com/problems/permutations-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2384/1/)

## 题目

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

```plain
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

---

## 思路1

使用`path`记录一组解，`vis` 记录该位置是否被选择过。

> 时间复杂度 $O(N \times n!)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        vis = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int u)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                if(i && nums[i - 1] == nums[i] && !vis[i - 1]) continue;
                path[u] = nums[i];
                vis[i] = true;
                dfs(nums, u + 1);
                vis[i] = false;
            }
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
