public class Solution {
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Arrays.sort(S);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if(S.length==0) return ans;
        int kk = 0;
        kk = 1 << (S.length);
        for(int i=0;i<kk;i++){
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            int digit = 0;
            int k = i;
            int index = 0;
            while(index<S.length){
                digit = k & 1;
                k >>= 1;
                if(digit==0){
                    tmp.add(S[index]);
                }
                index++;
            }
            ans.add(tmp);
        }
        return ans;
    }
}