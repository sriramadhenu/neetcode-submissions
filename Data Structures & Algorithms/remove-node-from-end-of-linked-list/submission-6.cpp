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
        int trail = -1;
        ListNode* fast = head;
        ListNode* trailer = head;
        while (fast){
            if (trail == n) trailer = trailer->next;
            else trail++;
            fast = fast->next;
        }
        // at this point, we can simply remove the node AFTER trailer
        // special case: n = the length of the list (trail never equalled n)
        // then, remove the head (or trailer itself)

        if (trail < n) return head->next;

        trailer->next = trailer->next->next;
        return head;
    }
};
