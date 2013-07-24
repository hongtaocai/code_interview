public class Solution {
    public void sortColors(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length<=1) return;
        int a1,a2,a3;
        a1 = a2 = a3 = 0;
        a2 = a3 = A.length-1;
        
        while(a1<=a2){
            if(A[a1]==0){
                a1++;
                continue;
            }
            if(A[a1]==2){
                A[a1] = A[a3];
                A[a3] = 2;
                a3--;
                if(a2>a3){
                    a2 = a3;
                }
                continue;
            }
            if(A[a1]==1){
                A[a1] = A[a2];
                A[a2] = 1;
                a2--;
                continue;
            }
        }
    }
}