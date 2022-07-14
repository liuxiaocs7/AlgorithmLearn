/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    boolean res = true;

    public boolean isBalanced(TreeNode root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;

        int left = dfs(root.left);
        int right = dfs(root.right);
        if (Math.abs(left - right) > 1) {
            res = false;
            return 0;
        }
        return Math.max(left, right) + 1;
    }
}