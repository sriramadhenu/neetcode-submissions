class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int running = 0, maximum = INT_MIN;
        for (int right = 0; right < nums.size(); right++){
            running = max(running + nums[right], nums[right]);
            maximum = max(maximum, running);
        }
        return maximum == INT_MIN ? -1 : maximum;
    }
};
