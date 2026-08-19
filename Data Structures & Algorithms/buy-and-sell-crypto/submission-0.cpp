class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int runningMin = prices[0];
        int bestProfit = 0;
        for (int i = 1; i < prices.size(); i++){
            int profit = prices[i] - runningMin;
            bestProfit = max(bestProfit, profit);
            runningMin = min(runningMin, prices[i]);
        }
        return bestProfit;
    }
};
