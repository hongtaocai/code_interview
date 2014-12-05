public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int sum1[] = new int[prices.length];
        int sum2[] = new int[prices.length];
        
        int minV = Integer.MAX_VALUE;
        int maxV = Integer.MIN_VALUE;
        int maxP = 0;
        
        for(int i=0;i<prices.length;i++){
            if(prices[i]<minV) minV = prices[i];
            if(prices[i]-minV>maxP) {
                maxP = prices[i]-minV;
            }
            sum1[i] = maxP;
        }
        
        maxP = 0;
        
        for(int i=0;i<prices.length;i++){
            if(prices[prices.length-1-i]>maxV){
                maxV = prices[prices.length-1-i];
            }
            if(maxV-prices[prices.length-1-i]>maxP){
                maxP = maxV-prices[prices.length-1-i];
            }
            sum2[prices.length-1-i] =maxP;
        }
        
        maxP = 0;
        
        for(int i=0;i<prices.length;i++){
            if(maxP<sum1[i]+sum2[i]) maxP = sum1[i]+sum2[i];
        }
        return maxP;
    }
}