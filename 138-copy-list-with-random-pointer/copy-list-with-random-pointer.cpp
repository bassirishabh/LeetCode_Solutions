/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> umap;
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        if(umap.find(head)!=umap.end()) return umap[head];
        Node* newnode=new Node(head->val);
        umap[head]=newnode;
        newnode->next=copyRandomList(head->next);
        newnode->random=copyRandomList(head->random);
        return newnode;
    }
};