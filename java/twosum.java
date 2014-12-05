public class Solution {
    
    HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
    
    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        hm.clear();
        int ans[] = new int[2];
        for(int i=0;i<numbers.length;i++){
            hm.put(numbers[i],i);
        }
        for(int i=0;i<numbers.length;i++){
            Integer t = hm.get(target-numbers[i]);
            if(t!=null){
                ans[0] = Math.min(t,i);
                ans[1] = Math.max(t,i);
                ans[0]++;
                ans[1]++;
                return ans;
            }
        }
        return ans;
    }
}