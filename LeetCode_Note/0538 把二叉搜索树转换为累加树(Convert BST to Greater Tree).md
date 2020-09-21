# 0538 把二叉搜索树转换为累加树(Convert BST to Greater Tree)

> 题目链接：[力扣](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/) | [LeetCode](https://leetcode.com/problems/convert-bst-to-greater-tree/) | [AcWing](3)

## 题目

给定一个二叉搜索树（`Binary Search Tree`），把它转换成为累加树（`Greater Tree`)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

```plain
输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
```

注意：本题和 [1038](https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/) 相同

---

## 思路1

> 二叉搜索树的中序遍历是一个**单调递增**的有序序列。如果我们反序地中序遍历该二叉搜索树，即可得到一个单调递减的有序序列。

【反序中序遍历】

由观察可以发现比一个结点的值更大的结点均在这个结点的右边，反序中序遍历该二叉搜索树，记录过程中的节点值之**和**，并不断更新当前遍历到的节点的节点值，即可得到题目要求的累加树。

> 时间复杂度 $O(N)$，$N$是二叉搜索树的节点个数，每个结点恰好被遍历一次，空间复杂度 $O(N)$，为递归过程中栈的开销，平均情况下为 $O(logn)$，最坏情况下树为链状结构，为 $O(N)$

## 代码1

```cpp
class Solution {
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;

        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);

        return root;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
