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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        
        if(root != null) queue.offer(root);
        while(!queue.isEmpty()) {
            int size = queue.size();
            int maxV = Integer.MIN_VALUE;
            for(int i = 0; i < size; i++) {
                TreeNode t = queue.poll();
                maxV = Math.max(maxV, t.val);
                if(t.left != null) queue.offer(t.left);
                if(t.right != null) queue.offer(t.right);
            }
            res.add(maxV);
        }
        return res;
    }
}