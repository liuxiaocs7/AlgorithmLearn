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
    private TreeNode prev;

    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(-1);
        prev = dummy;
        dfs(root);
        return dummy.right;
    }

    private void dfs(TreeNode root) {
        if(root == null) return;

        dfs(root.left);
        prev.right = root;
        prev = root;
        root.left = null;
        dfs(root.right);
    }
}