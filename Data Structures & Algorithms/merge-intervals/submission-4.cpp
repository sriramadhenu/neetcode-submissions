class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++){
            vector<int> newInterval(2);
            newInterval[0] = intervals[i][0];
            newInterval[1] = intervals[i][1];
            while (i + 1 < n and intervals[i + 1][0] <= newInterval[1]){
                newInterval[1] = max(newInterval[1], intervals[i + 1][1]);
                i++;
            }
            result.push_back(newInterval);
        }
        return result;
    }
};
