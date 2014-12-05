public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        boolean increasing;
        int lowP;
        int highP;
        if(prices==null || prices.length<2){
            return 0;
        }
        if(prices[0]<prices[1]){
            lowP = prices[0];
            highP = prices[1];
            increasing = true;
        }
        else{
            lowP = prices[1];
            highP = prices[0];
            increasing = false;
        }
        
        
        int Profit = 0;
        for(int i=2;i<prices.length;i++){
            if(prices[i]>prices[i-1]){
                if(increasing == false){
                    lowP = prices[i-1];
                    increasing = true;
                }
            }else{
                if(increasing == true ){
                    highP = prices[i-1];
                    Profit += (highP-lowP);
                    increasing = false;
                }
            }
        }
        if(increasing == true){
            highP = prices[prices.length-1];
            Profit += highP-lowP;
        }
        return Profit;
    }
}