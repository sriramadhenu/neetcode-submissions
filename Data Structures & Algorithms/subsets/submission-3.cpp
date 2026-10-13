class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {{}};
        vector<vector<int>> result;
        vector<int> current;

        function<void(int)> backtrack = [&](int start){
            result.push_back(current);
            for (int i = start; i < nums.size(); i++){
                current.push_back(nums[i]);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
