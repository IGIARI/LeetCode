/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* prev = NULL, * cur = head;
        if (head && head->next) {
            head = head->next;
        }
        while (cur && cur->next) {
            ListNode* a = cur;
            ListNode* b = cur->next;
            a->next = b->next;
            b->next = a;
            if (prev) {
                prev->next = b;
            }
            prev = a;
            cur = prev->next;
        }
        return head;
    }
};