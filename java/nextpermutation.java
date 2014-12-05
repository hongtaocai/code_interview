public class Solution {
    
    public void reverse(int[] num, int left, int right){
        while(left<right){
            int tmp = num[left];
            num[left] = num[right];
            num[right] = tmp;
            left++;
            right--;
        }
    }
    
    
    public void nextPermutation(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int last = num.length-1;
        while(true){
            if(last==0){
                break;
            }
            if(num[last]<=num[last-1]){
                last--;
            }else{
                break;
            }
        }
        if(last==0){
            reverse(num,0,num.length-1);
            return;
        }
        int start = last-1;
        int i;
        for(i=last;i<num.length;i++){
            if(num[i]<=num[start]){
                break;
            }
        }
        int tmp = num[start];
        num[start] = num[i-1];
        num[i-1] = tmp;
        reverse(num,last,num.length-1);
        return;
    }
}