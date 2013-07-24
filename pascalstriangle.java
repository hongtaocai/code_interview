public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(numRows==0) return res;
        ArrayList<Integer> firstRow = new ArrayList<Integer>();
        firstRow.add(1);
        res.add(firstRow);
        if(numRows==1) return res;
        ArrayList<Integer> secondRow = new ArrayList<Integer>();
        secondRow.add(1);
        secondRow.add(1);
        res.add(secondRow);
        if(numRows==2) return res;
        
        for(int i=2;i<numRows;i++){
            ArrayList<Integer> last = res.get(res.size()-1);
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for(int j=0;j<=last.size();j++){
                if(j==0 || j==last.size()){
                    tmp.add(1);
                }
                else{
                    tmp.add(last.get(j-1)+last.get(j));
                }
            }
            res.add(tmp);
        }
        
        return res;
        
    }
}