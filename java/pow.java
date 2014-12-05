public class Solution {
    public double pow(double x, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(n==0) return 1;
        if(x==0) return 0;
        if(n==1) return x;
        if(n==-2147483648) return 1/pow(x,2147483647)/x;
        if(n<0) return 1/pow(x,-n);
        if(n%2==1){
            double k = pow(x,n/2);
            return k*k*x;
        }
        else{
            double k = pow(x,n/2);
            return k*k;
        }
    }
}