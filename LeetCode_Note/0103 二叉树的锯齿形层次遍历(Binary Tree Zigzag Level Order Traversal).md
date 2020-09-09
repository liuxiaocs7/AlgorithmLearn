# 0103 二叉树的锯齿形层次遍历(Binary Tree Zigzag Level Order Traversal)

> 题目链接：[力扣](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/) | [LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2456/1/)

## 题目

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树[3,9,20,null,null,15,7],

```plain
    3
   / \
  9  20
    /  \
   15   7
```

返回锯齿形层次遍历如下：

```plain
[
  [3],
  [20,9],
  [15,7]
]
```

---

## 思路1

本题的本意是Z字形遍历，在102题的基础上增加了按照**奇偶行**需要改变遍历方向的方式进行遍历。设置一个记录当前行号的变量 `cnt = 0` 当 `cnt` 为奇数时需要进行翻转。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);
        int cnt = 0;
        while(!q.empty())
        {
            vector<int> row;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                row.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(cnt++ % 2) reverse(row.begin(), row.end());
            ans.push_back(row);
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
