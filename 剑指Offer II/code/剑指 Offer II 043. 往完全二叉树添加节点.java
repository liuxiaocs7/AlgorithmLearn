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
class CBTInserter {
    private final TreeNode root;
    private final Queue<TreeNode> queue;

    public CBTInserter(TreeNode root) {
        this.root = root;
        queue = new LinkedList<>();

        if(root != null) queue.offer(root);
        while(!queue.isEmpty() && queue.peek().left != null && queue.peek().right != null) {
            TreeNode node = queue.poll();
            queue.offer(node.left);
            queue.offer(node.right);
        }
    }
    
    public int insert(int v) {
        TreeNode node = new TreeNode(v);
        TreeNode parent = queue.peek();

        if(parent.left == null) {
            parent.left = node;
        } else {
            parent.right = node;
            queue.offer(parent.left);
            queue.offer(parent.right);
            queue.poll();
        }
        return parent.val;
    }
    
    public TreeNode get_root() {
        return this.root;
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */