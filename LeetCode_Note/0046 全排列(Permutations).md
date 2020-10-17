# 0046 全排列(Permutations)

> 题目链接：[力扣](https://leetcode-cn.com/problems/permutations/) | [LeetCode](https://leetcode.com/problems/permutations/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2383/1/)

## 题目

给定一个 **没有重复** 数字的序列，返回其所有可能的全排列。

示例:

```plain
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

---

## 思路1

【回溯】从前往后逐位枚举，每次选择一个没有被使用过的数，选好之后，将该数的状态改为已被使用，同时将该数记录在相应的位置上，然后递归选择下一个位置，递归返回时，将该数的状态改为**未被使用过**，并将该数从对应的位置上删除。

> 时间复杂度 $O(N * N!)$，空间复杂度 $O(N)$

搜索树中共有 $n!$ 个叶节点，叶节点处记录方案的计算量是 $O(n)$

## 代码1

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        vis = vector<bool>(nums.size());

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

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                path[u] = nums[i];
                vis[i] = true;
                dfs(u + 1, nums);
                vis[i] = false;
            }
        }
    }
};
```

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    boolean[] vis;
    List<Integer> path = new ArrayList<Integer>();

    void dfs(int u, int[] nums) {
        if(u == nums.length) {
            ans.add(new ArrayList<Integer>(path));
            return;
        }

        for(int i = 0; i < nums.length; i++) {
            if(!vis[i]) {
                path.add(nums[i]);  // 添加
                vis[i] = true;
                dfs(u + 1, nums);
                vis[i] = false;
                path.remove(path.size() - 1);  // 移除
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        vis = new boolean[nums.length];
        dfs(0, nums);
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
