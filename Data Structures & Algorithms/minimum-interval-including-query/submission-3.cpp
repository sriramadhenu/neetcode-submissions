class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for (auto& [q, idx] : sortedQueries){
            while (i < intervals.size() and intervals[i][0] <= q){
                int size = intervals[i][1] - intervals[i][0] + 1;
                pq.push({size, intervals[i][1]});
                i++;
            }
            while (!pq.empty() and pq.top().second < q) pq.pop();
            if (!pq.empty()) result[idx] = pq.top().first;
        }
        return result;
    }
};
