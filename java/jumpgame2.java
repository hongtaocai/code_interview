public class Solution {
    public int jump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        // Start typing your Java solution below
        // DO NOT write main() function
        
        
        int min = 0;
        int max = 0;
        int step = 0;
        while(max<A.length-1){
            int nextmin = max+1;
            int nextmax = 0;
            for(int i=min;i<=max;i++){
                if(nextmax < A[i]+i){
                    nextmax = A[i]+i;
                }
            }
            if(nextmin<=nextmax){
                min = nextmin;
                max = nextmax;
                step++;
            }
            else{
                break;
            }
        }
        if(max>=A.length-1){
            return step;
        }
        return Integer.MAX_VALUE;
    }
}