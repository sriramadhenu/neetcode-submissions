class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = 0, n = intervals.size();
        vector<vector<int>> result;
        while (index < n and intervals[index][1] < newInterval[0]){
            result.push_back(intervals[index]);
            index++;
        }
        while (index < n and intervals[index][0] <= newInterval[1]){
            // starts before the new one ends, so overlap
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        result.push_back(newInterval);
        while (index < n){
            result.push_back(intervals[index]);
            index++;
        }
        return result;
    }
};
