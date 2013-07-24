public class Solution {
    public String getPermutation(int n, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n==0) return "";
        if(n==1) return "1";
        int t = 1;
        int sn = n;
        k--;
        while(sn-1>0){
            t*=(sn-1);
            sn--;
        }
        boolean tt[] = new boolean[n];
        StringBuilder sb = new StringBuilder("");
        for(int i=0;i<n;i++){
            int r = k/t;
            k %= t;
            if(n-1-i!=0){
                t /= (n-1-i);
            }
            
            int j=0;
            int kk=0;
            while(j<r || tt[kk] == true ){
                if(tt[kk]==false){
                    j++;
                }
                kk++;
            }
            tt[kk] = true;
            sb.append((char)(kk+'1'));
            
        }
        return sb.toString();
    }
}