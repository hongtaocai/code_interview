public class Solution {
    public boolean canJump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int max = 0;
        int i=0;
        while(i<= max && i<A.length){
            if(A[i]+i>max){
                max = A[i]+i;
            }
            i++;
        }
        return max>=A.length-1;
    }
}