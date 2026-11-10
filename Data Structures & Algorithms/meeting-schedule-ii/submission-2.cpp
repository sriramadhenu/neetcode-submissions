/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> endTimes;
        int rooms = 0;
        for (const Interval& interval : intervals){
            while (!endTimes.empty() && endTimes.top() <= interval.start) endTimes.pop();
            endTimes.push(interval.end);
            rooms = max(rooms, (int)endTimes.size());
        }
        return rooms;
    }
};
