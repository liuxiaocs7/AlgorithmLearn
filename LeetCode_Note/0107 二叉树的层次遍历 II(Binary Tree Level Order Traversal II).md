# 0107 二叉树的层次遍历 II(Binary Tree Level Order Traversal II)

> 题目链接：[力扣](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/) | [LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2460/1/)

## 题目

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

```plain
    3
   / \
  9  20
    /  \
   15   7
```

返回其自底向上的层次遍历为：

```plain
[
  [15,7],
  [9,20],
  [3]
]
```

---

## 思路1

在题102的基础上，此题要求从叶子结点层开始输出，即最后将结果使用 `reverse` 翻转即可。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> row;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                row.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(row);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
