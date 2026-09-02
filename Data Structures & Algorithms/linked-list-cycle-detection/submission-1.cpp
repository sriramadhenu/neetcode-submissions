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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while (head){
            int cur_size = seen.size();
            seen.insert(head);
            int new_size = seen.size();
            if (new_size == cur_size) return true;
            head = head->next;
        }
        return false;
    }
};
