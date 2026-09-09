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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* trailer = head;
        int i = 1;

        while (fast && fast->next){
            if (i != 1) trailer = trailer->next;
            slow = slow->next;
            fast = fast->next->next;
            i++;
        }

        // "cut"
        ListNode* temp1 = trailer->next;
        trailer->next = nullptr;
        trailer = temp1;

        // now, take the list starting from slow, and reverse it
        ListNode* curr = slow;
        ListNode* prev = nullptr;

        while (curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // at this point, prev is the head of the reversed list
        // now, merge the two lists (starting with head and with prev) with alternating order
        while (head && prev){
            ListNode* nextFirst = head->next;
            ListNode* nextSecond = prev->next;
            head->next = prev;
            if (nextFirst != nullptr) prev->next = nextFirst;
            head = nextFirst;
            prev = nextSecond;
        }
    }
};
