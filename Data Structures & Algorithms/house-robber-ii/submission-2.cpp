class Solution {
public:
    int robRange(vector<int>& nums, int start, int end){
        int len = end - start + 1;
        vector<int> dp(len + 1);
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= len; i++){
            dp[i] = max(dp[i - 2] + nums[start + i - 1], dp[i - 1]);
        }
        return dp[len];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};
