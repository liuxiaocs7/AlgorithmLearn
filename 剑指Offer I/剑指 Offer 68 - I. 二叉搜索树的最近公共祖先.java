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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int a = root.val, b = p.val, c = q.val;
        if ((a <= b && a >= c) || (a <= c && a >= b)) return root;
        if (a < b && a < c) return lowestCommonAncestor(root.right, p, q);
        if (a > b && a > c) return lowestCommonAncestor(root.left, p, q);
        return null;
    }
}