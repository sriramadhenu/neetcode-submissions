class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size() + 1, 1);
        dp[0] = 0;
        int maxLen = 1;
        for (int i = 1; i <= nums.size(); i++){
            for (int j = 1; j < i; j++){
                if (nums[i - 1] > nums[j - 1]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(dp[i], maxLen);
        }
        return maxLen;
    }
};
