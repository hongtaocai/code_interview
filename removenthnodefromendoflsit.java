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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(head==null) return null;
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode p = prev;
        ListNode q = prev;
        for(int i=0;i<n;i++){
            p = p.next;
        }
        while(p.next!=null){
            p = p.next;
            q = q.next;
        }
        q.next= q.next.next;
        return prev.next;
    }
}