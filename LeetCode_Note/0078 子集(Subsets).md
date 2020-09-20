# 0078 子集(Subsets)

> 题目链接：[力扣](https://leetcode-cn.com/problems/subsets/) | [LeetCode](https://leetcode.com/problems/subsets/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2427/1/)

## 题目

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

```plain
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

---

## 思路1

【DFS】遍历每个位置的所有情况(1.放这个数字 2.不放这个数字)，将每一种结果放入 `ans` 中。

> 时间复杂度 $O(2^N \times N)$，空间复杂度 $O(N)$

## 代码1

使用全局变量

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }

    void dfs(int u, vector<int> &nums)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();
        dfs(u + 1, nums);
    }
};
```

使用局部变量

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, nums, path, ans);
        return ans;
    }

    void dfs(int u, vector<int>& nums, vector<int> path, vector<vector<int>> &ans)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[u]);
        dfs(u + 1, nums, path, ans);
        path.pop_back();
        dfs(u + 1, nums, path, ans);
    }
};
```

---

## 思路2

【迭代法实现子集枚举】假设集合大小是 $n$，我们枚举 $0 \cdots 2^n−1$，一共 $2^n$ 个数。
每个数表示一个**子集**，假设这个数的二进制表示的第 $i$ 位是 `1`，则表示该子集包含第 `i` 个数，否则为 `0` 表示不包含。子集的个数即为解的个数。

> 时间复杂度 $O(2^N \times N)$，空间复杂度 $O(N)$

## 代码2

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++)
        {
            vector<int> path;
            for(int j = 0; j < n; j++)
                if((i >> j) & 1)
                    path.push_back(nums[j]);
            ans.push_back(path);
        }
        return ans;
    }
};
```
