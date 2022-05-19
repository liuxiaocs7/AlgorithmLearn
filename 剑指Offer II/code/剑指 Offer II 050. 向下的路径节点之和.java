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

    private Map<Integer, Integer> map;

    public int pathSum(TreeNode root, int targetSum) {
        map = new HashMap<>();
        map.put(0, 1);
        return dfs(root, targetSum, 0);
    }

    private int dfs(TreeNode root, int targetSum, int path) {
        if(root == null) return 0;

        path = path + root.val;
        int count = map.getOrDefault(path - targetSum, 0);
        map.put(path, map.getOrDefault(path, 0) + 1);
        count += dfs(root.left, targetSum, path);
        count += dfs(root.right, targetSum, path);
        map.put(path, map.get(path) - 1);
        return count;
    }
}