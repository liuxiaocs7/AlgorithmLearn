/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head.next;
        ListNode slow = head;
        while(fast != null && fast.next != null) {
            if(fast == slow) return fast;
            slow = slow.next;
            fast = fast.next.next;
        }
        return null;
    }
}