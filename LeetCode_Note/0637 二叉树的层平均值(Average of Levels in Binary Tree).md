# 0637 二叉树的层平均值(Average of Levels in Binary Tree)

> 题目链接：[力扣](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | [AcWing](3)

## 题目

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

示例 1：

```plain
输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
```

提示：

节点值的范围在32位有符号整数范围内。

---

## 思路1

可参考[0102 二叉树的层序遍历(Binary Tree Level Order Traversal)](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)，本题在上题的基础上增加了求平均值，记录每一层的**和**以及**个数**即可。

注意一层的节点值之和有可能爆 `int` 需要使用 `long long`来求和。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            long long sum = 0;
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();
                sum += p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ans.push_back((double)sum / sz);
        }
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
