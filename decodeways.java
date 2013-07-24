public class Solution {
    public int numDecodings(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.length()==0) return 0;
        
        
        int k[] = new int[s.length()+1];
        if(s.charAt(0)=='0'){
            k[1]=0;
        }else{
            k[1]=1;
        }
        
        if(s.length()==1) return k[1];
        
        k[2] = 0;
        
        if(Integer.parseInt(s.substring(0,2))<27 && 
        Integer.parseInt(s.substring(0,2))>0 &&
        s.charAt(0)!='0'){
            k[2]++;
        }
        if(s.charAt(1)!='0'){
            k[2]+=k[1];
        }
        
        for(int i=3;i<=s.length();i++){
            k[i] = 0;
            if(s.charAt(i-1)!='0'){
                k[i] += k[i-1];
            }
            if(s.charAt(i-2)!='0' && Integer.parseInt(s.substring(i-2,i))<27){
                k[i] += k[i-2];
            }
        }
        return k[s.length()];
    }
}