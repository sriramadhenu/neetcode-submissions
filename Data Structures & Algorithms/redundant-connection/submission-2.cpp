class Solution {
public:
    int findParent(int node, vector<int>& parent){
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto& e : edges){
            int a = findParent(e[0], parent), b = findParent(e[1], parent);
            if (a == b) return e;
            parent[a] = b;
        }
        return {};
    }
};
