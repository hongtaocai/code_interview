public class Solution {
    public boolean isPalindrome(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(x<0) return false;
        if(x<10) return true;
        int k = 1;
        int kx = x;
        while(true){
            if(kx<10){
                break;
            }else{
                kx/=10;
                k*=10;
            }
        }
        
        
        while(x>=10){
            int left = x/k;
            int right = x%10;
            if(left!=right){
                return false;
            }
            x = x%k;
            x = x/10;
            k/=100;
        }
        return true;
    }
}