class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++){
            vector<int> newInterval = intervals[i];
            while (i + 1 < intervals.size() and intervals[i + 1][0] <= newInterval[1]){
                newInterval[1] = max(newInterval[1], intervals[i + 1][1]);
                i++;
            }
            result.push_back(newInterval);
        }
        return result;
    }
};
