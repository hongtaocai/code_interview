/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool myfunction (Interval i,Interval j) { return (i.start<j.start); } 

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> mergedIntervals;
        if(intervals.size()==0) {
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end(), myfunction);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1;i<intervals.size(); ++i) {
            if(intervals[i].start <= end) {
                end = max(end, intervals[i].end);
            } else {
                mergedIntervals.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        mergedIntervals.push_back(Interval(start,end));
        return mergedIntervals;
    }
};
