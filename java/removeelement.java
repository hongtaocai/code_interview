public class Solution {
    public int removeElement(int[] A, int elem) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int last = A.length-1;
        int i=0;
        while(i<=last){
            if(A[i]==elem){
                A[i]=A[last];
                last--;
            }
            else{
                i++;
            }
        }
        return i;
    }
}