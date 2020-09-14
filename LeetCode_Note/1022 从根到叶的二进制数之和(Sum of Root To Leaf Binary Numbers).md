# 1022 从根到叶的二进制数之和(Sum of Root To Leaf Binary Numbers)

> 题目链接：[力扣](https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/) | [LeetCode](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/) | [AcWing](3)

## 题目

给出一棵二叉树，其上每个结点的值都是 `0` 或 `1` 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为`0 -> 1 -> 1 -> 0 -> 1`，那么它表示二进制数 `01101`，也就是 `13` 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 $10^9 + 7$ 为模，返回这些数字之和。

示例：

![题目](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/04/05/sum-of-root-to-leaf-binary-numbers.png)

```plain
输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

提示：

树中的结点数介于 `1` 和 `1000` 之间。
`node.val` 为 `0` 或 `1` 。

---

## 思路1

遍历每一个从根结点到叶子结点的路径，将求得的和累加，每遍历深一层均将当前数字左移一位再加上当前值(0,1)。

> 时间复杂度 $O(N)$，空间复杂度 $O(logN)$

## 代码1

```cpp
class Solution {
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode *root, int val)
    {
        if(!root) return;
        val = (val << 1) + root->val;
        if(!root->left && !root->right) ans += val;
        dfs(root->left, val);
        dfs(root->right, val);
    }
};
```

---

## 思路2

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码2

```cpp

```
