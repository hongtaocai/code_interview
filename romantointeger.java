public class Solution {
    
    static HashMap<Character,Integer> hs = new HashMap<Character,Integer>();
    
    static {
        hs.put('I',1);
        hs.put('V',5);
        hs.put('X',10);
        hs.put('L',50);
        hs.put('C',100);
        hs.put('D',500);
        hs.put('M',1000);
    }
    
    public int romanToInt(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int ans = 0;
        for(int i=0;i<s.length();i++){
            
            if(i+1<s.length() && hs.get(s.charAt(i))<hs.get(s.charAt(i+1))){
                ans += hs.get(s.charAt(i+1)) - hs.get(s.charAt(i));
                i++;
            }
            else{
                ans += hs.get(s.charAt(i));
            }
        } 
        return ans;
    }
}