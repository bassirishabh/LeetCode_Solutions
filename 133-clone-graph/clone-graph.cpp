/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> umap;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(umap.find(node)!=umap.end()) return umap[node];
        Node* newnode=new Node(node->val);
        umap[node]=newnode;
        for(auto nei:node->neighbors){
            newnode->neighbors.push_back(cloneGraph(nei));
        }
        return newnode;
    }
};