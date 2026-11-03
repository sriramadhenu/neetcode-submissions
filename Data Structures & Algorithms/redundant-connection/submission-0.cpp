class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n + 1);
        vector<bool> visited(n + 1, false);

        function<bool(int, int)> dfs = [&](int node, int target){
            if (node == target) return true;
            visited[node] = true;
            for (int nei : adjList[node]){
                if (!visited[nei] && dfs(nei, target)) return true;
            }
            return false;
        };

        for (auto& e : edges){
            int a = e[0], b = e[1];
            fill(visited.begin(), visited.end(), false);
            if (dfs(a, b)) return e;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        return {};
    }
};
