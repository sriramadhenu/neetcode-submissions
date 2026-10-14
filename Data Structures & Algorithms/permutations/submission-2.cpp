class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        function<void()> dfs = [&](){
            if (current.size() == nums.size()){
                result.push_back(current);
                return;
            }

            for (int i = 0; i < nums.size(); i++){
                if (used[i]) continue;
                current.push_back(nums[i]);
                used[i] = true;
                dfs();
                current.pop_back();
                used[i] = false;
            }
        };

        dfs();
        return result;
    }
};
