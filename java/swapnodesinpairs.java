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
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode pPre = new ListNode(0);
        pPre.next = head;
        ListNode pfirst = head;
        ListNode p = head;
        ListNode pnext = head;
        ListNode lastpnext = pPre;
        int no = 0;
        while(p!=null){
            no++;
            if(no==2){
                no=0;
                pnext = p.next;
                pfirst = lastpnext.next;
                lastpnext.next = p;
                p.next = pfirst;
                pfirst.next = pnext;
                lastpnext = pfirst;
                p = pfirst;
            }
            p = p.next;
        }
        return pPre.next;
    }
}