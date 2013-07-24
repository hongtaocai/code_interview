public class Solution {
    public void merge(int A[], int m, int B[], int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int i = m+n-1;
        int ai = m-1;
        int bi = n-1;
        while(i>=0){
            if(ai==-1){
                A[i] = B[bi];
                i--;
                bi--;
            }
            else if(bi==-1 || A[ai]>B[bi]){
                A[i] = A[ai];
                i--;
                ai--;
            }else{
                A[i] = B[bi];
                i--;
                bi--;
            }
        }
    }
}