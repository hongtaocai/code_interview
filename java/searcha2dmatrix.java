public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int x = matrix.length;
        int y = matrix[0].length;
        int left = 0;
        int right = x*y-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            int midval = matrix[mid/y][mid%y];
            if( midval > target){
                right = mid-1;
            }else if(midval < target){
                left = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
}