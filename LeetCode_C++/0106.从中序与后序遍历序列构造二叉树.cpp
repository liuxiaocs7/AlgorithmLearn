/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
// @lc code=end

