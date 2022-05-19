/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "#";
        }

        String leftStr = serialize(root.left);
        String rightStr = serialize(root.right);
        return String.valueOf(root.val) + "," + leftStr + "," + rightStr;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strs = data.split(",");
        int[] i = {0};
        return dfs(strs, i);
    }

    private TreeNode dfs(String[] strs, int[] i) {
        String str = strs[i[0]];
        i[0]++;

        if("#".equals(str)) {
            return null;
        }

        TreeNode root = new TreeNode(Integer.parseInt(str));
        root.left = dfs(strs, i);
        root.right = dfs(strs, i);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));