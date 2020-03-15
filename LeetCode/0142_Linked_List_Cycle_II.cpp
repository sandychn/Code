// Time  : 12 ms
// Memory: 9.2 MB

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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) return nullptr;
            fast = fast->next;
            if (slow == fast) break;
        }
        if (fast == nullptr) return nullptr;
        ListNode* start = slow;
        int lengthOfCycle = 1;
        for (slow = slow->next, fast = fast->next; slow != start; ++lengthOfCycle, slow = slow->next, fast = fast->next);
        slow = fast = head;
        for (int i = 0; i < lengthOfCycle; i++) fast = fast->next;
        while (slow != fast) slow = slow->next, fast = fast->next;
        return slow;
    }
};
