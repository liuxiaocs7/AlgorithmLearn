/*
 * @lc app=leetcode.cn id=1022 lang=java
 *
 * [1022] 从根到叶的二进制数之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int res = 0;

    public int sumRootToLeaf(TreeNode root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode root, int val) {
        if(root == null) return;
        if(root.left == null && root.right == null) {
            res = res + (val << 1) + root.val;
        }

        dfs(root.left, (val << 1) + root.val);
        dfs(root.right, (val << 1) + root.val);
    }
}
// @lc code=end

