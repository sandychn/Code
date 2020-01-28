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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *p = nullptr;
        int c = 0;
        while (l1 != nullptr || l2 != nullptr || c > 0) {
            if (l1 != nullptr) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                c += l2->val;
                l2 = l2->next;
            }
            if (head == nullptr) {
                head = p = new ListNode(c % 10);
            } else {
                p->next = new ListNode(c % 10);
                p = p->next;
            }
            c /= 10;
        }
        return head;
    }
};