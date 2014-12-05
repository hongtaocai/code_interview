public class Solution {
    
    
    
    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.length()==0 && p.length()==0 ) {
            return true;
        }
        else if(p.startsWith(".*")){
            for(int i=0;i<=s.length();i++){
                if(isMatch(s.substring(i),p.substring(2))){
                    return true;
                }
            }
            return false;
        }else if(p.startsWith(".")){
            if(s.length()==0) return false;
            return isMatch(s.substring(1),p.substring(1));
        }else if(p.length()>=2 && p.charAt(1)=='*' ){
            
            if(s.length()==0){
                return isMatch(s,p.substring(2));
            } 
            
            int i=0;
            
            if(isMatch(s.substring(0),p.substring(2))){
                return true;
            }
            
            while(i<s.length() && p.charAt(0)==s.charAt(i)){
                if(isMatch(s.substring(i+1),p.substring(2))){
                    return true;
                }
                i++;
            }
            
            return false;
        }else if(p.length()>=1 ){
            if(s.length()==0) return false;
            
            if(s.charAt(0)!=p.charAt(0)){
                return false;
            }
            return isMatch(s.substring(1),p.substring(1));
        }else{
            return false;
        }
    }
}