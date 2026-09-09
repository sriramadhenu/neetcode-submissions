/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // at this point, prev points to the "Tail", or the "head" of the reverse
        // remove the nth node

        if (n == 1){
            prev = prev->next;
        } else {
            ListNode* ptr = prev;
            for (int c = 1; c < n - 1; c++) ptr = ptr->next;
            // now, cut
            // ptr points to the node BEFORE the one that needs to be cut
            ptr->next = ptr->next->next;
        }

        // reverse again, starting at prev

        ListNode* curr1 = prev;
        ListNode* prev1 = nullptr;

        while (curr1){
            ListNode* temp = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = temp;
        }
        return prev1;
    }
};
