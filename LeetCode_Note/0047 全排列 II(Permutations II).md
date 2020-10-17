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

【DFS】

1. 对数组从小到大排序，使得相同的数是相邻的
2. 从前往后枚举当前数组中没有选过的元素，由于相同的数保证从第一个开始用，直到最后一个，才会保证**枚举的顺序**不会出现重复的情况，若 `nums[i] == nums[i - 1]`，并且 `i - 1` 位置元素未使用过，则表示该枚举情况不符合需要枚举下一种情况
3. 将枚举到的元素插入到当前存数字的数组 `path` 中，并标记为已使用过，递归到下一层，直到枚举完所有数为止（`u == n`），把当前链表 `path` 加入到答案的 `ans` 中，并进行回溯，恢复现场，把使用过的标记为未使用过

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
        dfs(0, nums);
        return ans;
    }

    void dfs(int u, vector<int>& nums)
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
                vis[i] = true;
                path[u] = nums[i];
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
    List<Integer> path = new ArrayList<Integer>();
    boolean[] vis;

    void dfs(int u, int[] nums) {
        if(u == nums.length) {
            ans.add(new ArrayList<Integer>(path));
            return;
        }

        for(int i = 0; i < nums.length; i++) {
            if(!vis[i]) {
                if(i > 0 && nums[i - 1] == nums[i] && !vis[i - 1]) continue;
                vis[i] = true;
                path.add(nums[i]);
                dfs(u + 1, nums);
                vis[i] = false;
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
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
