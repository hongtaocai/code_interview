import java.util.Stack;

public class Solution {
    
    
    public int maximalRectangle(char[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        class Node{
        int h;
        int i;
            Node(int h, int i){
                this.h = h;
                this.i = i;
            }
        }
    
        
        if(matrix.length==0){
            return 0;
        }
        int x = matrix.length;
        int y = matrix[0].length;
        int height[] = new int[y];
 
        int max = 0;
        Stack<Node> st = new Stack<Node>();
        for(int i=0;i<x;i++){
            
            for(int j=0;j<y;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }
                else{
                    height[j]++;
                }
            }
            
            for(int j=0;j<y;j++){
                if(st.empty() || st.peek().h < height[j]){
                    st.push(new Node(height[j],j));
                }
                else if(st.peek().h > height[j]){
                    int prev = 0;
                    while(!st.empty() && st.peek().h > height[j] ){
                        Node e = st.pop();
                        max = Math.max(max,(j-e.i)*e.h);
                        prev = e.i;
                    }
                    st.push(new Node(height[j],prev));
                }
            }
            
            while(!st.empty()){
                Node e = st.pop();
                max = Math.max(max,(y-e.i)*e.h);
            }
            
        }
        return max;
    }
}