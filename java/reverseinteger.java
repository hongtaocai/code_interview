public class Solution {
    public int reverse(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int k = Math.abs(x);
       
        int r = 1;
        int ans = 0;
        while(k>=10){ // !!!!!!
            r = k%10;
            ans *=10;
            ans += r;
            k/=10;
        }
        ans *=10;
        ans +=k;
        if(x<0) ans = -ans;
        return ans;
    }
}