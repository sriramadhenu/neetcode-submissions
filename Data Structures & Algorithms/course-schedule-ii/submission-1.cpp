class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<int> order;

        unordered_map<int, vector<int>> adjList;
        for (const auto& prereq : prerequisites){
            adjList[prereq[0]].push_back(prereq[1]);
        }

        function<bool(int)> dfs = [&](int index) -> bool{
            if (state[index] == 1) return false;
            if (state[index] == 2) return true;

            state[index] = 1;
            for (int neighbor : adjList[index]){
                if (!dfs(neighbor)) return false;
            }

            state[index] = 2;
            order.push_back(index);
            return true;
        };

        for (int i = 0; i < numCourses; i++){
            if (!dfs(i)) return {};
        }
        return order;
    }
};
