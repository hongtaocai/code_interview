public class Solution {
        private class Node{
        char c;
        int index;
        Node(char c, int index){
            this.c = c;
            this.index = index;
        }
    }

    public int longestValidParentheses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Node> stack = new Stack<Node>();
        stack.push(new Node(')',-1));
        int max = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')' && stack.peek().c =='('){
                stack.pop();
                if(i-stack.peek().index>max){
                    max = i-stack.peek().index;
                }
            }
            else{
                stack.push(new Node(s.charAt(i),i));
            }
        }
        return max;
    }
}