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
    class Node{
        ListNode n;
        int from;
        Node(ListNode pp, int ff){
            n = pp;
            from = ff;
        }
    }
    
    class MyCmp implements Comparator<Node>{
        public int compare(Node n1, Node n2){
            return n1.n.val-n2.n.val;
        }
    }
    
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(lists.size()==0){
            return null;
        }
        if(lists.size()==1){
            return lists.get(0);
        }
        
        ListNode res = new ListNode(0);
        ListNode tail = res;    
    
        PriorityQueue<Node> pq = new PriorityQueue<Node>(lists.size(),new MyCmp());
        ListNode p[] = new ListNode[lists.size()];
        for(int i=0;i<lists.size();i++){
            p[i] = lists.get(i);
        }
        for(int i=0;i<p.length;i++){
            if(p[i]!=null){
                pq.add(new Node(p[i],i));
            }
        }
        while(!pq.isEmpty()){
            Node tmp = pq.poll();
            tail.next = tmp.n;
            tail = tail.next;
            p[tmp.from] = p[tmp.from].next;
            if(p[tmp.from]!=null){
                pq.add(new Node(p[tmp.from],tmp.from));
            }
        }
        return res.next;
    }
}