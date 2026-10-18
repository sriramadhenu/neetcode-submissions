class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int diff = max(s1, s2) - min(s1, s2);
            pq.push(diff);
        }

        return (pq.empty()) ? 0 : pq.top();
    }
};
