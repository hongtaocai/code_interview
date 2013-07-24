public class Solution {
    public int lengthOfLastWord(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i=0;
        for(;i<s.length();i++){
            if(s.charAt(s.length()-i-1)!=' '){
                break;
            }
        }
        int t = i;
        
        for(;i<s.length();i++){
            if(s.charAt(s.length()-i-1)==' '){
                return i-t;
            }
        }
        return s.length()-t;
    }
}