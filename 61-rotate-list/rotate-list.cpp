/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(head==NULL || k==0) return head;
        int length=1;
        while(curr->next!=NULL){
            length++;
            curr=curr->next;
        }
        curr->next=head;
        k=k%length;

        int end=length-k;
        ListNode* cur=head;
        int j=0;
        while(cur && j<end-1){
            cur=cur->next;
            j++;
        }
        head=cur->next;
        
        cur->next=NULL;
        cout<<cur->val;
        return head;
    }
};