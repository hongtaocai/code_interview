import java.util.regex.*;

public class Solution {
    public boolean isNumber(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Pattern p1 = Pattern.compile("^\\s*[+-]?((\\d+(\\.(\\d+)?)?)|(\\.\\d+))([eE][+-]?\\d+)?\\s*$");
        Matcher m1 = p1.matcher(s);
        
        return m1.find() ;
    }
}