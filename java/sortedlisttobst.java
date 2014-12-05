/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedArrayToBST(int[] num, int start, int end){
        if(num==null || num.length==0 || start>end){
            return null;
        }
        
        if(start==end){
            TreeNode tn = new TreeNode(num[start]);
            tn.left = null;
            tn.right = null;
            return tn;
        }
        int mid = start + (end-start)/2;
        TreeNode tn = new TreeNode(num[mid]);
            tn.left = sortedArrayToBST(num,start,mid-1);
            tn.right =  sortedArrayToBST(num,mid+1,end);
            return tn;
    }
    
    
    public int[] convert(ListNode head){
        int length = 0;
        ListNode t = head;
        while(t!=null){
            length++;
            t = t.next;
        }
        int res[] = new int[length];
        t = head;
        int i=0;
        while(t!=null){
            res[i] = t.val;
            i++;
            t = t.next;
        }
        
        return res;
    }
    

    
    public TreeNode sortedListToBST(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int k[] = convert(head);
        return sortedArrayToBST(k,0,k.length-1);
    }
}