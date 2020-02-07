// Time  : 52 ms (85.08%)
// Memory: 16.8 MB (39.79%)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA);
        int lengthB = getListLength(headB);
        if (lengthA > lengthB) {
            swap(headA, headB);
            swap(lengthA, lengthB);
        }
        // lengthA <= lengthB.
        for (int i = 0; i < lengthB - lengthA; i++) headB = headB->next;
        while (headA != nullptr) { // if headA != nullptr, so does headB.
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int getListLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) ++len, head = head->next;
        return len;
    }
};
