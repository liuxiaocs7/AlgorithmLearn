# 0113 路径总和 II(Path Sum II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/path-sum-ii/) | [LeetCode](https://leetcode.com/problems/path-sum-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2475/1/)

## 题目

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明:叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 `$sum = 22$`，

```plain
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
```

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

---

## 思路1

与 112 题类似只不过需要保存所有路径

> 时间复杂度 `$O(N^2)$`，空间复杂度 `$O(N)$`  
除了记录路径这部分，每个节点仅被遍历一次，且维护 sum 和路径的复杂度都是 O(1)，所以时间复杂度是 O(n)；而记录路径这部分：n个节点的二叉树的叶子节点数最多是 O(n) 级别的，且路径的长度最多也是 O(n) 级别的，所以时间复杂度最坏是 O(n2)。

## 代码1

```cpp
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum)
    {
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum == root->val)
            ans.push_back(path);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
