public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        rowIndex++;
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(rowIndex==0) return res;
        res.add(1);
        if(rowIndex==1) return res;
        res.add(1);
        if(rowIndex==2) return res;
        
        for(int i=3;i<=rowIndex;i++){
            for(int j=res.size()-1;j>=1;j--){
                res.set(j,res.get(j)+res.get(j-1));
            }
            res.add(1);
        }
        
        return res;
    }
}