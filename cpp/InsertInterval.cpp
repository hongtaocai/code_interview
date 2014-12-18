/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size() ==0) {
            res.push_back(newInterval);
            return res;
        }
        bool newIntervalInserted = false;
        for(int i=0;i<intervals.size();++i) {
            if(newIntervalInserted) {
                res.push_back(intervals[i]);
            } else if(newInterval.start > intervals[i].end) {
                res.push_back(intervals[i]);
            } else if(newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                newIntervalInserted = true;
            } else{
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
        }
        if(!newIntervalInserted) {
            res.push_back(newInterval);
        }
        return res;
    }
};
