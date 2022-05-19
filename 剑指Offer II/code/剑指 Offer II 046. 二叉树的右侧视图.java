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
    public List<Integer> rightSideView(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> res = new ArrayList<>();
        if(root != null) q.offer(root);
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode t = q.poll();
                if(i == size - 1) res.add(t.val);
                if(t.left != null) q.offer(t.left);
                if(t.right != null) q.offer(t.right);
            }
        }
        return res;
    }
}