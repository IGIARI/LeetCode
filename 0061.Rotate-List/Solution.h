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
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 0;
        ListNode* p = head;
        ListNode *prev, *tail, *tmp;
        while (p) {
            if (p->next == NULL)
                tail = p;
            p = p->next;
            len++;
        }
        if (len <= 1)
            return head;
        k = k % len;
        if (k == 0)
            return head;
        p = head;
        int i = 0;
        while (i < len - k) {
            prev = p;
            p = p->next;
            i++;
        }
        tail->next = head;
        prev->next = NULL;
        head = p;
        return head;
    }
};