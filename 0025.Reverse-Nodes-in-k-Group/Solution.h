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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) {
            return head;
        }
        
        ListNode* cur;
        ListNode* endOfPrev = NULL;
        ListNode* beginOfCur = head;
        while (true) {
            cur = beginOfCur;
            int i = 0;
            for (i = 0; i < k - 1; i++) {
                if (cur && cur->next) {
                    cur = cur->next;
                } else {
                    break;
                }
            }
            if (i < k - 1) {
                break;
            }
            
            cur = beginOfCur;
            ListNode* next = cur->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* tmp = next->next;
                next->next = cur;
                cur = next;
                next = tmp;
            }
            if (endOfPrev) {
                endOfPrev->next = cur;
                endOfPrev = beginOfCur;
                beginOfCur->next = next;
                beginOfCur = next;
            } else {
                endOfPrev = head;
                head->next = next;
                head = cur;
                beginOfCur = next;
            }
        }
        return head;
    }
};