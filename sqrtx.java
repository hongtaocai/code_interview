public class Solution {
    public int sqrt(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        double t = x;
        while(Math.abs(t*t-x)>1e-6){
            t = (t + x/t)/2;
        }
        return (int)t;
    }
}