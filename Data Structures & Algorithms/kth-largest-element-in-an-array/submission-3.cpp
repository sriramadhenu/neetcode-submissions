class Solution {
public:
    void add(priority_queue<int, vector<int>, greater<int>>& pq, int num, int k){
        pq.push(num);
        if (pq.size() > k) pq.pop();
    }

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) add(pq, num, k);
        return pq.top();
    }
};
