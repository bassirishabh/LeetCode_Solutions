/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nxt=node->next;
        int temp=nxt->val;
        nxt->val=node->val;
        node->val=temp;
        node->next=nxt->next;
        delete(nxt);
    }
};