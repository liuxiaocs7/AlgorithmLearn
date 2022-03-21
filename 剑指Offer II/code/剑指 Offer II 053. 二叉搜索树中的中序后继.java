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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode cur = root;
        TreeNode res = null;
        while(cur != null) {
            if(cur.val > p.val) {
                res = cur;
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return res;
    }
}