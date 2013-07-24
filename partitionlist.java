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
    public ListNode partition(ListNode head, int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        ListNode head1 = new ListNode(0);
        ListNode head2 = new ListNode(0);
        ListNode tail1 = head1;
        ListNode tail2 = head2;
        
        ListNode p = head;
        while(p!=null){
            if(p.val<x){
                tail1.next = p;
                tail1 = tail1.next;
            }
            else{
                tail2.next = p;
                tail2 =tail2.next;
            }
            p = p.next;
        }
        
        tail1.next = head2.next;
        tail2.next = null;
        return head1.next;
        
    }
}