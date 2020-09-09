# 0112 路径总和(Path Sum)

> 题目链接：[力扣](https://leetcode-cn.com/problems/path-sum/) | [LeetCode](https://leetcode.com/problems/path-sum/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2474/1/)

## 题目

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明:叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 $sum = 22$，

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

【递归】，**自顶向下**从根节点往叶节点走，每走过一个节点，就让 `sum` 减去该节点的值，则如果走到某个叶节点时，`sum` 恰好为0，则说明从根节点到这个叶节点的路径上的数的和等于 `sum`。
只要找到一条满足要求的路径，递归即可返回。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum -= root->val;
        if(!root->left && !root->right) return !sum;  // 叶子结点，看减完最后结果是不是0
        // 有左子树并且左子树中存在一天和为sum的路径(右子树同理)
        return root->left && hasPathSum(root->left, sum) || root->right && hasPathSum(root->right, sum);
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root ->left && !root->right) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }

    bool dfs(TreeNode *root, int sum)
    {
        if(!root) return false;
        if(!root->left && !root->right)
            return sum == root->val;

        return dfs(root->left, sum - root->val) || dfs(root->right, sum - root->val);
    }
};
```
