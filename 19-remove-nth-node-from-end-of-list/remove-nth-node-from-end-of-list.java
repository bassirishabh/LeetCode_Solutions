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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return head;

        ListNode dummy=new ListNode(0);
        dummy.next=head;

        ListNode slow=dummy;
        ListNode fast=dummy;

        while(n>=0){
            fast=fast.next;
            n-=1;
        }
         while(fast!=null){
            slow=slow.next;
            fast=fast.next;
        }
        ListNode middle=slow.next;
        slow.next=slow.next.next;
        return dummy.next;
    }
}