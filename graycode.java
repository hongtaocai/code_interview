public class Solution {
    public ArrayList<Integer> grayCode(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n==0) {
            ArrayList<Integer> res = new ArrayList<Integer>();
            res.add(0);
            return res;
        }
        
        ArrayList<Integer> a = grayCode(n-1);
        int s = 1<<(n-1);
        
        for(int i=a.size()-1;i>=0;i--){
            a.add(a.get(i)|s);    
        }
        return a;
    }
}