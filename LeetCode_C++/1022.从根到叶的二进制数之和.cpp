/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode *root, int val)
    {
        if(!root) return;
        val = val << 1 | root->val;
        if(!root->left && !root->right)
            ans += val;
        dfs(root->left, val);
        dfs(root->right, val);
    }
};
// @lc code=end

