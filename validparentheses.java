public class Solution {
    
    HashSet<Character> right;
    HashSet<Character> left;
    HashMap<Character,Character> right2left;
    
    private boolean isPureValid(String s){
        Stack<Character> st = new Stack<Character>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(right.contains(c) && st.empty()){
                return false;
            }
            else if(right.contains(c) && !st.empty() && st.peek().equals(right2left.get(c))){
                st.pop();
            }
            else{
                st.push(c);    
            }
        }
        return st.empty();
    }
    
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        right = new HashSet<Character>();
        left = new HashSet<Character>();
        right2left = new HashMap<Character,Character>();
       right.add(new Character(')'));
        right.add(new Character('}'));
        right.add(new Character(']'));
        left.add(new Character('('));
        left.add(new Character('['));
        left.add(new Character('{'));
        right2left.put(new Character(')'),new Character('('));
        right2left.put(new Character(']'),new Character('['));
        right2left.put(new Character('}'),new Character('{'));
        return isPureValid(s);
  
        
        
    }
}