class Solution {
public:
    int findParent(int node, vector<int> parent){
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (const auto& edge : edges){
            int rootU = findParent(edge[0], parent), rootV = findParent(edge[1], parent);
            if (rootU == rootV) continue;
            parent[rootU] = rootV;
            components--;
        }

        return components;
    }
};
