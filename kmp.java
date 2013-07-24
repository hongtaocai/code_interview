public class Solution {
    public String strStr(String haystack, String needle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(needle.length()==0){
            return haystack;
        }
        
        int next[] = new int[needle.length()];
        int j=0;
        int t = -1;
        next[0] =-1;
        while(j<needle.length()-1){
            if(t<0 || needle.charAt(j)==needle.charAt(t)){
                j++;
                t++;
                next[j]=t;
            }
            else{
                t=next[t];
            }
        }
        
        t=0;
        j=0;
        
        while(t<needle.length() && j< haystack.length() ){
            if(t<0 || needle.charAt(t)==haystack.charAt(j) ){
                t++;
                j++;
            }else{
                t=next[t];
            }
        }
        if(t==needle.length())
            return haystack.substring(j-t);
        else
            return null;
    }
}