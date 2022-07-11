/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer> list = new ArrayList<>();

    public int[] reversePrint(ListNode head) {
        dfs(head);
        return list.stream().mapToInt(i->i).toArray();
    }

    void dfs(ListNode head) {
        if (head == null) return;
        dfs(head.next);
        list.add(head.val);
    }
}