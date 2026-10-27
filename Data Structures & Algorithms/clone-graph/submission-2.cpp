/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> clones;

        function<Node*(Node*)> dfs = [&](Node* cur) -> Node* {
            if (clones.count(cur)) return clones[cur];
            
            Node* copy = new Node(cur->val);
            clones[cur] = copy;

            for (Node* neighbor : cur->neighbors){
                copy->neighbors.push_back(dfs(neighbor));
            }

            return copy;
        };

        return dfs(node);
    }
};
