/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Interval> res = new ArrayList<Interval>();
        Interval merge = new Interval();
        boolean added = false;
        for(Interval i : intervals){
           if(i.end<newInterval.start){
               res.add(i);
           }
           else if(i.start>newInterval.end){
               if(!added){
                   res.add(newInterval);
                   added = true;
               }
               res.add(i);
           }
           else{
               newInterval.start = Math.min(newInterval.start, i.start);
               newInterval.end = Math.max(newInterval.end, i.end);
           }
        }
        if(!added){
            res.add(newInterval);
        }
        return res;
    }
}