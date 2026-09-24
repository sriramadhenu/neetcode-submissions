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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2){
            if (list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1){
            vector<ListNode*> merged;
            for (int i = 0; i < lists.size(); i += 2){
                if (i + 1 < lists.size()) merged.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                else merged.push_back(lists[i]);
            }
            lists = merged;
        }
        return lists[0];
    }
};
