/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            long long sum = 0;
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();
                sum += p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ans.push_back((double)sum / sz);
        }
        return ans;
    }
};
// @lc code=end

