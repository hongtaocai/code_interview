public class Solution {
    public int search(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int left = 0;
        int right = A.length-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(target==A[mid]) return mid;
            if(A[left]<=A[mid] && A[mid]<=A[right]){
                if(target>A[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            else if(A[left]<=A[mid]){
                if(target>=A[left] && target<A[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(target>A[mid] && target<=A[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
}