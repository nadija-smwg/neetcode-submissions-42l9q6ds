class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next; // store next
            curr->next = prev;          // reverse link
            prev = curr;                // move prev
            curr = nxt;                 // move curr
        }
        return prev;
    }
};
