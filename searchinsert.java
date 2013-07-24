public class Solution {
    public int searchInsert(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int left = 0;
        int right = A.length-1;
        if(target<=A[left]) return 0;
        if(target>A[right]) return right+1;
        while(left<right){
            int mid = left + (right-left)/2 ;
            if(A[mid]==target) return mid;
            if(right==left+1){
                return right;
            }
            if(A[mid]>target){
                right = mid;
            }else{
                left = mid;
            }
        }
        return 0;
    }
}

// or
public class Solution {
    public int searchInsert(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int left = 0;
        int right = A.length-1;
        while(left<=right){
            int mid = left + (right-left)/2 ;
            if(A[mid]==target) return mid;
            else if(A[mid]>target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
}