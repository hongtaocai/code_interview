public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<ArrayList<Integer>> now = new Stack<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        
        for(int i=1;i<n+1;i++){
        ArrayList<Integer> al =new ArrayList<Integer>();
        al.add(i);
        now.push(al);
        }
        
        while(!now.isEmpty()){
            ArrayList<Integer> top = now.pop();
            int last = top.get(top.size()-1);
            if(top.size()==k ) {
                res.add(top);
                continue;
            }
            for(int i=last+1;i<n+1;i++){
                if(n-i>=k-top.size()-1){
                    ArrayList<Integer> tmp = new ArrayList<Integer>(top);
                    tmp.add(i);
                    now.push(tmp);
                }
                
            }
        }
        
        return res;
        
    }
}