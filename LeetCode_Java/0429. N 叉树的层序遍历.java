/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        Queue<Node> queue = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        if(root != null) queue.offer(root);

        while(!queue.isEmpty()) {
            int sz = queue.size();
            List<Integer> row = new ArrayList<>();
            for(int i = 0; i < sz; i++) {
                Node t = queue.poll();
                row.add(t.val);
                for(Node child : t.children) {
                    queue.offer(child);
                }
            }
            res.add(row);
        }
        return res;
    }
}