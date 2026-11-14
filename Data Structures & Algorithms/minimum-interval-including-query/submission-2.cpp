class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        int i = 0;

        for (auto& [q, idx] : sortedQueries){
            while (i < intervals.size() && intervals[i][0] <= q){
                int size = intervals[i][1] - intervals[i][0] + 1;
                heap.push({size, intervals[i][1]});
                i++;
            }
            while (!heap.empty() && heap.top().second < q) heap.pop();
            if (!heap.empty()) result[idx] = heap.top().first;
        }
        return result;
    }
};
