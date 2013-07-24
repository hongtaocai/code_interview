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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode head = new ListNode(0);
        ListNode p = head;
        ListNode p1 = l1;
        ListNode p2 = l2;
        while(true){
            if(p1==null){
                p.next = p2;
                break;
            }
            if(p2==null){
                p.next = p1;
                break;
            }
            if(p1.val<p2.val){
                p.next = p1;
                p = p.next;
                p1 = p1.next;
            }else{
                p.next = p2;
                p = p.next;
                p2 = p2.next;
            }
        }
        return head.next;
    }
}