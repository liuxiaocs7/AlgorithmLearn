# 0102 二叉树的层序遍历(Binary Tree Level Order Traversal)

> 题目链接：[力扣](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) | [LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/)
 | [AcWing](https://www.acwing.com/activity/content/problem/content/2455/1/)

## 题目

给你一个二叉树，请你返回其按**层序遍历**得到的节点值。（即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

```plain
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```plain
[
  [3],
  [9,20],
  [15,7]
]
```

---

## 思路1

【BFS】
宽度优先遍历，一层一层来做。即：

1. 将根节点插入队列中；
2. 创建一个新队列，用来按顺序保存下一层的所有子节点；
3. 对于当前队列中的所有节点，按顺序依次将儿子加入新队列，并将当前节点的值记录在答案中；
4. 重复步骤2-3，直到队列为空为止。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
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
