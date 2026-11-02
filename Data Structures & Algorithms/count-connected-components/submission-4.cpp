class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (const auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()){
                int top = q.front();
                q.pop();
                for (int nei : adjList[top]){
                    if (!visited[nei]){
                        q.push(nei);
                        visited[nei] = true;
                    }
                }
            }
        }

        return components;
    }
};
