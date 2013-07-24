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
    class MyC implements Comparator<Interval>{
        public int compare(Interval a, Interval b){
            return a.start-b.start;
        }
    }
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        
        ArrayList<Interval> res = new ArrayList<Interval>();
        if(intervals.size()==0) return res;
        Collections.sort(intervals,new MyC());
        int start = 0;
        int end = 0;
        for(int i=0;i<intervals.size();i++){
            if(i==0){
                start = intervals.get(i).start; 
                end = intervals.get(i).end;
            }
            else{
                if(intervals.get(i).start<=end){
                    end = Math.max(end,intervals.get(i).end);
                }
                else{
                    res.add(new Interval(start,end));
                    start = intervals.get(i).start;
                    end = intervals.get(i).end;
                }
            }
        }
        res.add(new Interval(start,end));
        return res;
    }
}