/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);
        int cnt = 0;
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
            if(cnt++ % 2) reverse(row.begin(), row.end());
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

