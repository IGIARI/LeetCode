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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int upper = 0;
        ListNode* first = NULL;
        ListNode* prev = first;
        ListNode* current = NULL;

        while (true) {
            int end1 = 0, end2 = 0;
            int v = 0;
            if (l1 != NULL) {
                v += l1->val;
                l1 = l1->next;
            } else {
                end1 = 1;
            }
            if (l2 != NULL) {
                v += l2->val;
                l2 = l2->next;
            } else {
                end2 = 1;
            }
            if (end1 == 1 && end2 == 1 && upper == 0) {
                break;
            }
            
            v += upper;
            upper = 0;
            if (v >= 10) {
                upper = 1;
                v = v % 10;
            }
            
            current = new ListNode(v);
            if (prev) {
                prev->next = current;
            } else {
                first = current;
            }
            prev = current;
        }
        return first;
    }
};
