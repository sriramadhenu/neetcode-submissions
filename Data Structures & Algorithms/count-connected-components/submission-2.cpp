class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (const auto& e : edges){
                if (e[0] == node){
                    if (!visited[e[1]]) dfs(e[1]);
                } else if (e[1] == node){
                    if (!visited[e[0]]) dfs(e[0]);
                }
            }
        };
        int numcomponents = 0;
        for (int i = 0; i < visited.size(); i++){
            if (!visited[i]){
                dfs(i);
                numcomponents++;
            }
        }
        return numcomponents;
    }
};
