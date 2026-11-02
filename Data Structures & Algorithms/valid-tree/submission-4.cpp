class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // given the nodes are labeled 0 to n - 1, we can just keep a vector<bool> visited
        // after running bfs or dfs on the root, return false if any value in visited is still false
        if (edges.size() != n - 1) return false;
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> adjList;
        for (const auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        function<void(int)> dfs = [&](int node){
            visited[node] = true;
            for (int neighbor : adjList[node]){
                if (!visited[neighbor]) dfs(neighbor);
            }
        };

        dfs(0);
        for (int i = 0; i < visited.size(); i++){
            if (!visited[i]) return false;
        }
        return true;
    }
};
