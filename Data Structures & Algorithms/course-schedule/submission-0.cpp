class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        for (const auto& prereq : prerequisites){
            adjList[prereq[0]].push_back(prereq[1]);
        }

        vector<int> state(numCourses, 0);

        function<bool(int)> dfs = [&] (int index) -> bool {
            if (state[index] == 1) return false;
            if (state[index] == 2) return true;

            state[index] = 1;
            for (int neighbor : adjList[index]){
                if (!dfs(neighbor)) return false;
            }

            state[index] = 2;
            return true;
        };

        for (int i = 0; i < numCourses; i++){
            if (state[i] == 0){
                if (!dfs(i)) return false;
            }
        }
        return true;
    }
};
