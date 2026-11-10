class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (const int& num : nums) total += num;
        if (total % 2 != 0) return false;
        vector<bool> dp(total / 2 + 1, false); // dp[i] answers if it is possible to create a partition of sum i
        dp[0] = true; // its possible to partition nums into an array that has a total of 0: no nums
        // cannot repeat numbers, so go top-down
        for (const int& num : nums){
            for (int i = dp.size() - 1; i >= num; i--){
                if (dp[i - num]) dp[i] = true;
            }
        }
        return dp[total / 2];
    }
};
