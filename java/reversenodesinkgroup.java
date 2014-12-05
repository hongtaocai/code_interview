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
    
    class Bundle {
        public ListNode beg;
        public ListNode end;
        Bundle(ListNode beg, ListNode end){
            this.beg = beg;
            this.end = end;
        }
    }
    
    private Bundle reverseBet(Bundle b){
        
        if(b.beg==b.end) return b;
        
        ListNode pPre = null;
        ListNode p = b.beg;
        ListNode tmp;
        while(p!=b.end){
            tmp = p.next;
            p.next = pPre;
            pPre = p;
            p = tmp;
        }
        p.next = pPre;
        return new Bundle(b.end,b.beg);
    }
    
    public ListNode reverseKGroup(ListNode head, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode ans = head;
        ListNode p = head;
        ListNode pPre = new ListNode(0);
        pPre.next = head;
        Bundle lastBundle = new Bundle(pPre,pPre);
        int no = 0;
        while(p!=null){
            no++;
            if(no==k){
                no=0;
                ListNode pnext = p.next;
                Bundle kb = reverseBet(new Bundle(lastBundle.end.next,p));
                lastBundle.end.next = kb.beg;
                kb.end.next = pnext;
                lastBundle = kb;
                p = kb.end;
            }
            p = p.next;
        }
        return pPre.next;
    }
}