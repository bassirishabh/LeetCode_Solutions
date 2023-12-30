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
    ListNode* reversell(ListNode* a){
        ListNode* curr=a;
        ListNode* prev=NULL;

        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* findkth(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL){

            ListNode* kth=findkth(temp,k);
            if(kth==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* nxt=kth->next;
            kth->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kth;
            }else{
                prev->next=kth;
            }
            prev=temp;
            temp=nxt;
        }
        return head;
    }
};