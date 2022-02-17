/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
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
// @lc code=end

