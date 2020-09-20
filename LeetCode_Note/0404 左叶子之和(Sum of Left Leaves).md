# 0404 左叶子之和(Sum of Left Leaves)

> 题目链接：[力扣](https://leetcode-cn.com/problems/sum-of-left-leaves/) | [LeetCode](https://leetcode.com/problems/sum-of-left-leaves/) | [AcWing](3)

## 题目

计算给定二叉树的所有左叶子之和。

```plain
示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

---

## 思路1

使用一个全局变量 `sum` 记录所有的和，如果左子树存在，检查左子树，如果是一个叶子结点加到 `sum` 上，递归求解左右子树。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

时间复杂度：$O(n)$，其中 $n$ 是树中的**节点个数**。

空间复杂度：$O(n)$。空间复杂度与深度优先搜索使用的栈的最大深度相关。在最坏的情况下，树呈现链式结构，深度为 $O(n)$，对应的空间复杂度也为 $O(n)$。

## 代码1

```cpp
class Solution {
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        if(root->left)
        {
            if(!root->left->left && !root->left->right)
                sum += root->left->val;
            sumOfLeftLeaves(root->left);
        }

        if(root->right)
        {
            sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
```

全局变量

```cpp
class Solution {
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        if(root->left && !root->left->left && !root->left->right)
            sum += root->left->val;

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
```

局部变量

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        int sum = 0;

        if(root->left && !root->left->left && !root->left->right)
            sum += root->left->val;

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
```

---

## 思路2

【BFS】遍历树中的每个结点，在其左子树不为空的情况下如果左子树是一个叶子结点将其加到 `ans` 中，否则加入队列 `q` 中；在其右子树不为空的情况下如果右子树不是叶子结点将其加入队列 `q`(叶子结点无需再遍历了，直接忽略)

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode *node)
    {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            if(t->left)
            {
                if(isLeaf(t->left))
                    ans += t->left->val;
                else
                    q.push(t->left);
            }

            if(t->right)
            {
                if(!isLeaf(t->right))
                    q.push(t->right);
            }
        }
        return ans;
    }
};
```
