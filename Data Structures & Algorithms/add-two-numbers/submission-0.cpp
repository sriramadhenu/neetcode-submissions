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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (carry != 0 || l1 || l2){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int num = a + b + carry;
            if (num > 9){
                carry = 1;
                num %= 10;
            }
            else carry = 0;
            tail->next = new ListNode(num);
            tail = tail->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};
