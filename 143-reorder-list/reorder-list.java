/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    public ListNode findmiddle(ListNode head){
        ListNode slow=head;
        ListNode fast=head;

        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast) break;
        }
        return slow;

    }

    public ListNode reverse(ListNode head){
        ListNode curr=head;
        ListNode prev=null;
        
        while(curr!=null){
            ListNode nxt=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }

    public void reorderList(ListNode head) {
        if(head==null) return ;

        ListNode middle=findmiddle(head);
        ListNode rev=reverse(middle);
        ListNode hd=head;
        ListNode sc=rev;
        while(sc.next!=null){
            ListNode nxt=hd.next;
            hd.next=sc;
            hd=nxt;

            nxt=sc.next;
            sc.next=hd;
            sc=nxt;
        }
    }
}