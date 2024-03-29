/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// @lc code=end

