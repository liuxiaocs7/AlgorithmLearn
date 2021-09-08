/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode reverseL1 = reverseList(l1);
        ListNode reverseL2 = reverseList(l2);

        ListNode addRes = addTwoList(reverseL1, reverseL2);

        return reverseList(addRes);
    }

    private ListNode addTwoList(ListNode r1, ListNode r2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        int t = 0;
        while(r1 != null || r2 != null || t != 0) {
            if(r1 != null) {
                t += r1.val;
                r1 = r1.next;
            }
            if(r2 != null) {
                t += r2.val;
                r2 = r2.next;
            }
            p.next = new ListNode(t % 10);
            p = p.next;
            t /= 10;
        }
        return dummy.next;
    }

    private ListNode reverseList(ListNode head) {
        ListNode prev = null, cur = head;
        while(cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
}