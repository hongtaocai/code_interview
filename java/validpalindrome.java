public class Solution {
    static HashSet<Character> hs ;
    
    static {
        hs = new HashSet<Character>();
        for(char a = 'a' ; a <= 'z'; a++){
            hs.add(a);
        }
        for(char a = '0' ; a <= '9'; a++){
            hs.add(a);
        }
    }


    public boolean isPalindrome(String s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length()<=1){
            return true;
        }
        s = s.toLowerCase();
        int left = 0;
        int right = s.length()-1;
        while(left<=right){
            if(!hs.contains(s.charAt(left))){
                left ++;
                continue;
            }
            if(!hs.contains(s.charAt(right))){
                right--;
                continue;
            }
            if(s.charAt(left)!=s.charAt(right)){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
    
    
}