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
    public ListNode rotateRight(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int length = 0;
        ListNode p = head;
        ListNode tail = head;
        while(p!=null){
            length++;
            tail = p;
            p = p.next;
        }
        if(length==0){
            return head;
        }
        n = n%length;
        if(n==0) return head;
        n = length-n;
        n = n-1;
        p = head;
        while(n>0){
            p = p.next;
            n--;
        }
        ListNode newhead = p.next;
        tail.next = head;
        p.next = null;
        return newhead;
    }
}