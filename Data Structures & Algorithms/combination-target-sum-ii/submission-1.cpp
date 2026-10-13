class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;

        function<void(int, int)> dfs = [&](int start, int runningSum){
            if (runningSum == target){
                result.push_back(current);
                return;
            }

            for (int i = start; i < candidates.size(); i++){
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                if (runningSum + candidates[i] > target) break;
                current.push_back(candidates[i]);
                dfs(i + 1, runningSum + candidates[i]);
                current.pop_back();
            }
        };

        dfs(0, 0);
        return result;
    }
};
