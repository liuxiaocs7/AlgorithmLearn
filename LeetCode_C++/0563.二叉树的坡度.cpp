/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = 0;
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }

    // dfs 返回以某个点为根结点的子树的所有节点的值
    int dfs(TreeNode* node) {
        if(!node) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);
        res += abs(l - r);
        return l + r + node->val;
    }
};
// @lc code=end

