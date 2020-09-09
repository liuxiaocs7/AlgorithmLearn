# 0106 从中序与后序遍历序列构造二叉树(Construct Binary Tree from Inorder and Postorder Traversal)

> 题目链接：[力扣](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2459/1/)

## 题目

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

```plain
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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

参考题105

递归建立整棵二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。

具体步骤如下：

1. 先利用**后序遍历**找**根节点**：后序遍历的最后一个数，就是根节点的值；
2. 在中序遍历中找到根节点的位置 $k$，则 $k$ 左边是左子树的中序遍历，右边是右子树的中序遍历；
3. 假设左子树的中序遍历的长度是 $l$，则在后序遍历中，前 $l$ 个数就是左子树的后序遍历，接下来的数除了最后一个，就是右子树的后序遍历；
4. 有了左右子树的后序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；

时间复杂度分析：我们在初始化时，用哈希表(`unordered_map<int,int>`)记录每个值在中序遍历中的位置，这样我们在递归到每个节点时，在中序遍历中查找根节点位置的操作，只需要 $O(1)$ 的时间。此时，创建每个节点需要的时间是 $O(1)$，所以总时间复杂度是 $O(n)$。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
    unordered_map<int, int> mp;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
    {
        if(pl > pr) return NULL;
        auto root = new TreeNode(postorder[pr]);
        int k = mp[root->val];
        root->left = build(inorder, postorder, il, k - 1, pl, pl + (k - 1 - il));
        root->right = build(inorder, postorder, k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
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
