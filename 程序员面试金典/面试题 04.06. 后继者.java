class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(root == null) return null;
        if(root.val <= p.val) return inorderSuccessor(root.right, p);
        TreeNode res = inorderSuccessor(root.left, p);
        return res == null ? root : res;
    }
}