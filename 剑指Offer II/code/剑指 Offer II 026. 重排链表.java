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
    public void reorderList(ListNode head) {
        int cnt = 0;
        ListNode p = head;
        while(p != null) {
            cnt++;
            p = p.next;
        }

        p = head;
        for(int i = 0; i < (cnt - 1) / 2; i++) {
            p = p.next;
        }

        ListNode front = head;
        ListNode q = p.next;
        p.next = null;
        ListNode last = reverseList(q);

        ListNode dummy = new ListNode(-1);
        p = dummy;
        while(last != null) {
            p.next = front;
            front = front.next;
            p = p.next;
            p.next = last;
            last = last.next;
            p = p.next;
        }
        if(front != null) {
            p.next = front;
        }
        head = dummy.next;
    }

    private ListNode reverseList(ListNode p) {
        ListNode prev = null;
        ListNode cur = p;
        while(cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
}