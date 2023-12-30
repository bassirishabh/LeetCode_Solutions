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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

     ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode* mid=findmid(head);
        ListNode* reversenode=reverse(mid);
        ListNode* hd=head;
        ListNode* sc=reversenode;
        while(sc->next!=NULL){
            ListNode* nxt=hd->next;
            hd->next=sc;
            hd=nxt;

            nxt=sc->next;
            sc->next=hd;
            sc=nxt;
        }


    }
};