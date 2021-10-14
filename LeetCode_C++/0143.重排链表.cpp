/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        auto mid = head;
        for(int i = 0; i < (n + 1) / 2 - 1; i++) mid = mid->next;

        auto tail = mid;
        for(auto p = mid, q = mid->next; q;) {
            auto ne = q->next;
            q->next = p, p = q, q = ne;
            tail = p;
        }

        for(auto p = head, q = tail; q != mid; ) {
            auto ne = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next, q = ne;
        }
        if(n % 2) mid->next = NULL;
        else mid->next->next = NULL;
    }
};
// @lc code=end

