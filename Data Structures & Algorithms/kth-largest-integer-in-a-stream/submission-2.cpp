class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    // we can store k elements in descending order and just return the final element and pop

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) add(num);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};
