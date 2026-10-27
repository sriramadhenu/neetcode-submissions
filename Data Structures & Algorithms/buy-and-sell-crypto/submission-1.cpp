class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0;
        int runningMin = prices[0];
        for (int i = 1; i < prices.size(); i++){
            int profit = prices[i] - runningMin;
            runningMin = min(runningMin, prices[i]);
            maximum = max(maximum, profit);
        }
        return maximum;
    }
};
