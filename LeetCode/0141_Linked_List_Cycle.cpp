// Time  : 12 ms
// Memory: 9.1 MB

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
