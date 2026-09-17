/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node dummy(0);
        Node* tail = &dummy;
        Node* orig = head;
        
        while (orig){
            Node* n = new Node(orig->val);
            map[orig] = n;
            tail->next = n;
            tail = n;
            orig = orig->next;
        }

        // use map to point each node's random to its counterpart
        Node* orig2 = head;
        while (orig2){
            Node* copy = map[orig2];
            copy->random = orig2->random ? map[orig2->random] : nullptr;
            orig2 = orig2->next;
        }

        return dummy.next;
    }
};
