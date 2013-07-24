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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(l1==null) return l2;
        if(l2==null) return l1;
        
        ListNode ans = new ListNode(0);
        ListNode res = ans;
        int add = 0;
        while(true){
            if(l1==null && l2==null){
                if(add!=0){
                    ans.next = new ListNode(1);
                    ans = ans.next;
                }
                break;
                
            }
            else if(l1!=null && l2==null){
                ans.next = new ListNode((add+l1.val)%10);
                add = (add+l1.val)/10;
                ans = ans.next;
                l1 = l1.next;
                
            }
            else if(l1==null && l2!=null){
                ans.next = new ListNode((add+l2.val)%10);
                add = (add+l2.val)/10;
                ans = ans.next;
                l2 = l2.next;
            }
            else{
                ans.next = new ListNode((add+l1.val+l2.val)%10);
                add = (add+l1.val+l2.val)/10;
                ans = ans.next;
                l1 = l1.next;
                l2 = l2.next;
            }
                
        }
        return res.next;
    }
}