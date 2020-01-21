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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        int size = 0;
        ListNode* p = head;
        while (p) ++size, p = p->next;
        if (n == size) {
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        }
        int time = size - n - 1;
        ListNode* pre = head;
        p = head->next;
        for (int i = 0; i < time; ++i) {
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
        delete p;
        return head;
    }
};