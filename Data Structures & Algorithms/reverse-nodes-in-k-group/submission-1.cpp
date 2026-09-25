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
    ListNode* reverseList(ListNode* start, ListNode* end){
        ListNode* prev = end;
        ListNode* curr = start;

        while (curr != end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true){
            ListNode* node = groupPrev->next;
            for (int i = 0; i < k; i++){
                if (!node) return dummy.next;
                node = node->next;
            }
            // node is now the first node after the group, so reverse everything UP to node
            // additionally, keep track of the rest of the list
            ListNode* groupStart = groupPrev->next;
            ListNode* newHead = reverseList(groupStart, node);

            groupPrev->next = newHead;
            groupPrev = groupStart;
        }
        return dummy.next;
    }
};
