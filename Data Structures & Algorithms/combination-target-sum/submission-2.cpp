class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;

        function<void(int, int)> backtrack = [&](int start, int runningSum){
            if (runningSum == target){
                result.push_back(current);
                return;
            }

            for (int i = start; i < nums.size(); i++){
                if (runningSum + nums[i] <= target){
                    current.push_back(nums[i]);
                    backtrack(i, runningSum + nums[i]);
                    current.pop_back();
                }
            }
        };

        backtrack(0, 0);
        return result;
    }
};
