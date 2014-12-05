/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode p = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode q = prev;
        int state = 0;
        if(p==null) return p;
        if(p.next==null) return p;
        while(p.next!=null){
            if(p.next.val==p.val){
                p.next = p.next.next;
                state = 1;
            }else{
                if(state==0){
                    q = p;
                    p = p.next;
                }else{
                    q.next = p.next;   
                    p = q.next;
                    state = 0;
                }
            }
        }
        if(state==1){
            q.next = null;
            state = 0;
        }
        
        return prev.next;
    }
}