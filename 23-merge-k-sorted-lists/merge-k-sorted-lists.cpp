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
     ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* l3=dummy;

        while(l1 && l2){
            if(l1->val<l2->val){
                dummy->next=l1;
                l1=l1->next;
            }else{
                dummy->next=l2;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        if(l1) dummy->next=l1;
        if(l2) dummy->next=l2;
        return l3->next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists,int left,int right){
        if(left<right){
            int mid=(left+right)/2;
            ListNode* l1=mergeSort(lists,left,mid);
            ListNode* l2=mergeSort(lists,mid+1,right);
            return merge(l1,l2);
        }
        return lists[left];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeSort(lists,0, lists.size()-1);
    }
};