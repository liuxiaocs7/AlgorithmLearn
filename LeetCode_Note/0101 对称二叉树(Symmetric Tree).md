# 0101 对称二叉树(Symmetric Tree)

> 题目链接：[力扣](https://leetcode-cn.com/problems/symmetric-tree/) | [LeetCode](https://leetcode.com/problems/symmetric-tree/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2454/1/)

## 题目

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。

```plain
    1
   / \
  2   2
 / \ / \
3  4 4  3
```

但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:

```plain
    1
   / \
  2   2
   \   \
   3    3
```

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

---

## 思路1

【递归】递归判断两个子树是否互为镜像。

两个子树互为**镜像**当且仅当：

1. 两个子树的根节点值相等；
2. 第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像；

当两个结点都为空表示当前子树对称，否则一个为空另一个不为空或者值不相等则肯定不对称，若都满足继续比较左节点的左子树和右节点的右子树以及左节点的右子树记忆右节点的左子树。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *l, TreeNode*r)
    {
        if(!l && !r) return true;
        if(!l || !r || l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
