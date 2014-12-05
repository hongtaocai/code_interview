public class Solution {
    public int[] searchRange(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] ans = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        if(A.length==0){
            return ans;
        }
        int left = 0;
        int right = A.length-1;
        int first = -1;
        while(left<=right){
            int mid = left + ((right-left)/2);
            if(A[mid]>target){
                right = mid-1;
            }else if(A[mid]<target){
                left = mid+1;
            }else{
                if(mid==0){
                    first=0;
                    break;
                }else{
                    if(A[mid-1]!=target){
                        first = mid;
                        break;
                    }
                    else{
                        right = mid-1;
                    }
                }
            }
        }
        if(first==-1) return ans;
        left = first;
        right = A.length-1;
        int second = -1;
        while(left<=right){
            int mid = left + ((right-left)/2);
            if(A[mid]>target){
                right = mid-1;
            }else if(A[mid]<target){
                left = mid+1;
            }else{
                if(mid==A.length-1){
                    second = A.length-1;
                    break;
                }else if(A[mid+1]!=target){
                    second = mid;
                    break;
                }else{
                    left = mid+1;
                }
            }
        }
        ans[0] = first;
        ans[1] = second;
        return ans;
    }
}