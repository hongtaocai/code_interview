public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(triangle.size()==0) return 0;
        
        
        int[] res = new int[triangle.size()];
        res[0] = triangle.get(0).get(0);
        for(int i=1;i<res.length;i++){
            for(int j=i;j>=0;j--){
                if(j==0){
                    res[j] += triangle.get(i).get(0);
                }else if(j==i){
                    res[j] = res[j-1] + triangle.get(i).get(i);
                }else{
                    res[j] = Math.min( res[j], res[j-1]) +  triangle.get(i).get(j);
                }
            }
        }
        int max = res[0];
        for(int i=1;i<res.length;i++){
            if(max>res[i]){
                max = res[i];
            }
        }
        return max;
    }
}