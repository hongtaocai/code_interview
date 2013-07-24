public class Solution {
    public int firstMissingPositive(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        for(int i=0;i<A.length;i++){
            if(A[i]<=0) A[i] = Integer.MAX_VALUE;
        }
        for(int i=0;i<A.length;i++){
            if(A[i]>0 && A[i]-1 < A.length && A[A[i]-1]!=A[i] ){
                int k=A[i];
                A[i]=A[k-1];
                A[k-1]=k;
                i--;
            }
        }
        for(int i=1;i<=A.length;i++){
            if(A[i-1]!=i){
                return i;
            }
        }
        return A.length+1;
    }
}