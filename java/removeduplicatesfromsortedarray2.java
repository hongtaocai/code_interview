public class Solution {
    public int removeDuplicates(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length==0) return 0;
        if(A.length==1) return 1;
        int count = 0;
        int i=1;
        int j=1;
        while(i<A.length){
            if(A[i]==A[i-1]){
                if(count==0){
                    count++;
                    A[j]=A[i];
                    i++;
                    j++;
                }else{
                    count++;
                    i++;   
                }
            }else{
                count=0;
                A[j]=A[i];
                i++;
                j++;
            }
        }
        return j;
    }
}