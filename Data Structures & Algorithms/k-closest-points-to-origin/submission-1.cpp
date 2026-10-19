class Solution {
public:
    int calculateDistance(int r, int c) { return r * r + c * c; }
    void add(priority_queue<pair<int, pair<int, int>>>& pq, int k, int num, int x, int y){
        pq.push({num, {x, y}});
        if (pq.size() > k) pq.pop();
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto& point : points){
            int distance = calculateDistance(point[0], point[1]);
            add(pq, k, distance, point[0], point[1]);
        }

        vector<vector<int>> result;
        while (!pq.empty()){
            auto [dist, p] = pq.top();
            pq.pop();
            result.push_back({p.first, p.second});
        }
        return result;
    }
};
