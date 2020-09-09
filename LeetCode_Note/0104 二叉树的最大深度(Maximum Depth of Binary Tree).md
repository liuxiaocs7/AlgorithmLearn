# 0104 二叉树的最大深度(Maximum Depth of Binary Tree)

> 题目链接：[力扣](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) | [LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2457/1/)

## 题目

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明:叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

```plain
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度3 。

---

## 思路1

【递归】当前树的最大深度等于左右子树的最大深度加1。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l, r) + 1;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
