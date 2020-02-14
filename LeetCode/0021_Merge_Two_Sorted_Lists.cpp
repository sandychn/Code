// Time  : 8 ms (86.57%)
// Memory: 9 MB (15.63%)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* previous = head;
        // while (l1 != nullptr || l2 != nullptr) {
        //     if (l2 == nullptr || (l1 != nullptr && l1->val <= l2->val)) {
        //         previous->next = l1;
        //         previous = l1;
        //         l1 = l1->next;
        //     } else {
        //         previous->next = l2;
        //         previous = l2;
        //         l2 = l2->next;
        //     }
        // }
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                previous->next = l1;
                l1 = l1->next;
            } else {
                previous->next = l2;
                l2 = l2->next;
            }
            previous = previous->next;
        }
        previous->next = (l1 == nullptr ? l2 : l1);

        ListNode* res = head->next;
        delete head;
        return res;
    }
};
