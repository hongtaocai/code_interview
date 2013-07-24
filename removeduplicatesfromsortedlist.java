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
        if(p==null) return p;
        if(p.next==null) return p;
        while(p.next!=null){
            if(p.next.val==p.val){
                p.next = p.next.next;
            }else{
                p = p.next;
            }
        }
        return head;
    }
}