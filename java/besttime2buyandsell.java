public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(prices==null || prices.length==0){
            return 0;
        }
        
        int maxProfit1 = 0 ;
        int minPrice = prices[0];
        for(int i=1;i<prices.length;i++){
            if(-minPrice+prices[i]>maxProfit1) maxProfit1 = -minPrice+prices[i];
            if(prices[i]<minPrice) minPrice = prices[i];
        }
        return maxProfit1;
    }
}