// Time  : 4 ms (98.71%)
// Memory: 9.3 MB (11.98%)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* after = current->next;
            current->next = previous;
            previous = current;
            current = after;
        }

        return previous;

        // Following is an O(n) space solution. 8 ms and 9.5 MB.

        // if (head == nullptr) {
        //     return nullptr;
        // }
        // stack<ListNode*> stk;
        // for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        //     stk.push(temp);
        // }
        // ListNode* ans = stk.top();
        // ListNode* last = stk.top();
        // stk.pop();
        // while (!stk.empty()) {
        //     ListNode* now = stk.top();
        //     stk.pop();
        //     last->next = now;
        //     last = now;
        // }
        // last->next = nullptr;
        // return ans;
    }
};
