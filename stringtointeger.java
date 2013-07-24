public class Solution {
    public int atoi(String str) {
        // Start typing your Java solution below
        // DO NOT write main() function
        str = str.trim();
        boolean neg = false;
        int start = 0;
        if(str.length()==0) return 0;
        if(str.charAt(0)=='+'){
            start = 1;
        }else if(str.charAt(0)=='-'){
            start = 1;
            neg = true;
        }
        long ans = 0;
        for(int i=start;i<str.length();i++){
            if(str.charAt(i)>'9' || str.charAt(i)<'0'){
                if(i==start) return 0;
                break;
            }
            else{
                long tmp = str.charAt(i)-'0';
                ans *= 10L;
                ans += tmp;
                if(!neg && ans>2147483647L){
                    return 2147483647;
                }else if(neg && ans>2147483648L){
                    return -2147483648;
                }
            }
        }
        if(neg){
            return -(int)ans;
        }else{
            return (int)ans;
        }
        
    }
}