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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while (l1 != NULL || l2 != NULL) {
            ListNode* tmp = new ListNode(0);
            if (head == NULL) {
                head = tmp;
                prev = tmp;
            } else {
                prev->next = tmp;
                prev = tmp;
            }
            if (l1 == NULL) {
                tmp->val = l2->val;
                l2 = l2->next;
                continue;
            }
            if (l2 == NULL) {
                tmp->val = l1->val;
                l1 = l1->next;
                continue;
            }
            if (l1->val <= l2->val) {
                tmp->val = l1->val;
                l1 = l1->next;
            } else {
                tmp->val = l2->val;
                l2 = l2->next;
            }
        }
        return head;
    }
};