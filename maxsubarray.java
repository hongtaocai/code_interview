public class Solution {
    public int maxSubArray(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int max = Integer.MIN_VALUE;
        if(A.length==0) return 0;
        int B[] = new int[A.length];
        for(int i=0;i<A.length;i++){
            if(i==0){
                B[i]=A[i];
            }
            else if(B[i-1]>0){
                B[i]=B[i-1]+A[i];
            }
            else{
                B[i]=A[i];
            }
            max = Math.max(max,B[i]);
        }
        return max;
    }
}