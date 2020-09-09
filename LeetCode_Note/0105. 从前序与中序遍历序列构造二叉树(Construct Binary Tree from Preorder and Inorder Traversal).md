# 0105. 从前序与中序遍历序列构造二叉树(Construct Binary Tree from Preorder and Inorder Traversal)

> 题目链接：[力扣](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2458/1/)

## 题目

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

```plain
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```

返回如下的二叉树：

```plain
    3
   / \
  9  20
    /  \
   15   7
```

---

## 思路1

【递归】先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。

具体步骤如下：

1. 先利用**前序遍历**找**根节点**：前序遍历的第一个数，就是根节点的值；
2. 在中序遍历中找到根节点的位置 $k$(利用创建的哈希表)，则 $k$ 左边是左子树的中序遍历，右边是右子树的中序遍历；
3. 假设左子树的中序遍历的长度是 $l$，则在前序遍历中，根节点后面的 $l$ 个数，是左子树的前序遍历，剩下的数是右子树的前序遍历；
4. 有了左右子树的前序遍历和中序遍历，我们可以先**递归**创建出左右子树，然后再创建根节点；

时间复杂度分析：我们在初始化时，用哈希表(`unordered_map<int,int>`)记录每个值在中序遍历中的位置，这样我们在递归到每个节点时，在中序遍历中查找根节点位置的操作，只需要 $O(1)$ 的时间。此时，创建每个节点需要的时间是 $O(1)$，所以总时间复杂度是 $O(n)$。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
    unordered_map<int,int> mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int il, int ir, int pl, int pr)
    {
        if(pl > pr) return NULL;
        auto root = new TreeNode(preorder[pl]);  // 根结点
        int k = mp[root->val];  // 根结点中序遍历中的位置
        root->left = build(preorder, inorder, il, k - 1, pl + 1, pl + 1 + (k - 1- il));
        root->right = build(preorder, inorder, k + 1, ir, pl + 1 + (k - 1- il) + 1, pr);
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
