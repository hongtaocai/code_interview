public class Solution {
    
    
    
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(height.length<2) return 0;
        int left = 0;
        int right = height.length-1;
        int maxV = (right-left)*Math.min(height[left],height[right]);
        while(left!=right){
            int value = (right-left)*Math.min(height[left],height[right]);
            if(value>maxV) maxV = value;
            if(height[left]>height[right]) right--;
            else left++;
        }
        return maxV;
    }
}