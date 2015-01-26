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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        return mergeLists(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeLists(vector<ListNode*> &lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l + 1 == r) {
            return (mergeTwoLists(lists[l], lists[r]));
        }
        int m = (l + r) / 2;
        return (mergeTwoLists(
            mergeLists(lists, l, m),
            mergeLists(lists, m + 1, r)
        ));
    }
    
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