# 0108 将有序数组转换为二叉搜索树(Convert Sorted Array to Binary Search Tree)

> 题目链接：[力扣](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [AcWing](https://www.acwing.com/activity/content/problem/content/2461/1/)

## 题目

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

```plain
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

---

## 思路1

一棵树是二叉搜索树等价于**中序遍历序列有序**。

BST的中序遍历是升序的，因此本题等同于根据中序遍历的序列恢复二叉搜索树。因此我们可以以升序序列中的任一个元素作为根节点，以该元素左边的升序序列构建左子树，以该元素右边的升序序列构建右子树，这样得到的树就是一棵二叉搜索树,又因为本题要求高度平衡，因此我们需要选择升序序列的中间元素作为根节点。

> 时间复杂度 $O(N)$，空间复杂度 $O(N)$

## 代码1

```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int> &nums, int l, int r)
    {
        if(l > r) return NULL; 
        int mid = (l + r) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
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
