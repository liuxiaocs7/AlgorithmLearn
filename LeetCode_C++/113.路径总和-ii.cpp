/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(sum == root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
};
// @lc code=end

