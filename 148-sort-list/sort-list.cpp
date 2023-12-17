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
    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* ptr=dummy;

        while(left && right){
            if(left->val<right->val){
                ptr->next=left;
                left=left->next;
            }else{
                ptr->next=right;
                right=right->next;
            }
            ptr=ptr->next;
        }
        if(left) ptr->next=left;
        if(right) ptr->next=right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=getmid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
};