class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> upper; // minheap for upper half
    priority_queue<int> lower; // maxheap for smaller half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if (upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        return (lower.size() > upper.size()) ? lower.top() : ((lower.top() + upper.top()) / 2.0);
    }
};
