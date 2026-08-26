class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxima;
        deque<int> dq; // stores indices, values in decreasing order front-to-back

        for (int right = 0; right < nums.size(); right++) {
            // remove indices from the back whose values are smaller than nums[right]
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            // remove the front index if it's fallen out of the window
            if (dq.front() <= right - k) {
                dq.pop_front();
            }

            // once the window has reached size k, record the max
            if (right >= k - 1) {
                maxima.push_back(nums[dq.front()]);
            }
        }

        return maxima;
    }
};