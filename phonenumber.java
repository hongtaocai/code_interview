public class Solution {
    public ArrayList<String> letterCombinations(String digits) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<String> last = new ArrayList<String>();
        ArrayList<String> now = new ArrayList<String>();
        HashMap<Character, String> map = new HashMap<Character, String>();
        map.put('2',"abc");
        map.put('3',"def");
        map.put('4',"ghi");
        map.put('5',"jkl");
        map.put('6',"mno");
        map.put('7',"pqrs");
        map.put('8',"tuv");
        map.put('9',"wxyz");
        
        last.add("");
        for(int i=0;i<digits.length();i++){
            if( (int)digits.charAt(i) <= (int) '9' &&
                (int)digits.charAt(i) >= (int) '2' ){
                    for(String e:last){
                        String next = map.get(digits.charAt(i));
                        for(int m=0;m<next.length();m++){
                            now.add(e+next.charAt(m));
                        }
                    }
                }
                ArrayList<String> tmp = last;
                last = now;
                now = tmp;
                now.clear();
        }
        return last;
        
    }
}