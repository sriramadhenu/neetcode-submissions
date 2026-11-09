class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxHere = nums[0], minHere = nums[0], best = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int n = nums[i];
            int a = n * maxHere;
            int b = n * minHere;

            maxHere = max({n, a, b});
            minHere = min({n, a, b});
            best = max(best, maxHere);
        }
        return best;
    }
};
