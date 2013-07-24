public class Solution {
    
    boolean used[];
    int res[];
    int num[];
    HashSet<ArrayList<Integer>> resSet;
    ArrayList<ArrayList<Integer>> reslist;
    
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        // Start typing your Java solution below
        // DO NOT rite main() function
        used = new boolean[num.length];
        res = new int[num.length];
        this.num = num;
        reslist = new ArrayList<ArrayList<Integer>>();
        resSet = new  HashSet<ArrayList<Integer>>();
        pu(0);
        reslist.addAll(resSet);
        return reslist;
    }
    
    public void pu(int x){
        for(int i=0;i<num.length;i++){
            if(used[i]==false){
                used[i] = true;
                res[x] = num[i];
                if(x==num.length-1){
                    ArrayList<Integer> y = new ArrayList<Integer>();
                    for(int j=0;j<res.length;j++){
                        y.add(res[j]);
                    }
                    resSet.add(y);
                }else{
                    pu(x+1);
                }
                used[i] = false;
            }
        }
    }
}