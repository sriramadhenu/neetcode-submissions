class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> current;

        function<void(int)> dfs = [&](int start){
            result.insert(current);
            for (int i = start; i < nums.size(); i++){
                current.push_back(nums[i]);
                dfs(i + 1);
                current.pop_back();
            }
        };

        dfs(0);

        vector<vector<int>> subsets(result.begin(), result.end());
        return subsets;
    }
};
