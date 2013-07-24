public class Solution {
    class Ele{
        
        public int h;
        public int i;
        Ele(int h, int i){
            this.h = h;
            this.i = i;
        }
    }
    
    public int largestRectangleArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        Stack<Ele> k = new Stack<Ele>();
        int max = 0;
        for(int i=0;i<height.length;i++){
            if(k.isEmpty() || height[i] > k.peek().h ){
                k.push(new Ele(height[i],i));
            }else{
                int prev = i;
                while(!k.isEmpty() && k.peek().h > height[i]){
                    Ele e = k.pop();
                    prev = e.i;
                    max = Math.max(max,(i-e.i)*e.h); 
                }   
                k.push(new Ele(height[i],prev));
            }
        }
        while(!k.isEmpty()){
            Ele e = k.pop();
            max = Math.max(max,(height.length-e.i)*e.h);  
        }
        
        return max;
    }
}