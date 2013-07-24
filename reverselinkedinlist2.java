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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(n-m<=0) return head;
        
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode p = prev;
        // reverse from p.next
        for(int i=0;i<m-1;i++){
            p = p.next;
        }
        ListNode pnext = p.next;
        ListNode qprev = p;
        ListNode qnext = p.next.next;
        ListNode q = p.next;
        for(int i=0;i<n-m;i++){
            q.next = qprev;
            qprev = q;
            q = qnext;
            qnext = qnext.next;
        }
        q.next = qprev;
        p.next = q;
        pnext.next = qnext;
        return prev.next;
    }
}