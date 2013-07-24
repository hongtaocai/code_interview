public class Solution {
    
    class Node{
        int index;
        int h;
        Node(int i, int h){
            this.index = i;
            this.h = h;
        }
    }
    
    public int trap(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length<=2) return 0;
        Node[] s = new Node[A.length];
        int sum = 0;
        int left = 0;
        int right = 1;
        int mid = 0;
        while(right<A.length && A[right]>=A[right-1]){
            right++;
        }
        if(right==A.length){
            return 0;
        }
        left = right-1;
        mid = right;
        int top = 0;
        s[top] = new Node(left,A[left]);
        top++;
        s[top] = new Node(mid,A[mid]);
        top++;
        right++;
        while(right<A.length){
            if(A[right]==s[top-1].h){
                right++;
            }
            else if(A[right]>s[top-1].h){
                left = top-2;
                while(s[left].h<A[right] && left>0){
                    left--;
                }
                for(int i=left;i<top-1;i++){
                    sum+=(right-s[i].index-1)*(A[right]-s[i+1].h);
                }
                while(s[left].h==A[right] && left>0){
                    left--;
                }
                top = left+1;
                s[top] = new Node(right,A[right]);
                top++;
                right++;
            }else{
                s[top] = new Node(right,A[right]);
                top++;
                right++;
            } 
        }
        return sum;
    }
}