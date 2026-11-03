class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int step = 2; step < dp.size(); step++){
            dp[step] = min(dp[step - 2] + cost[step - 2], dp[step - 1] + cost[step - 1]);
        }
        return dp[cost.size()];
    }
};
