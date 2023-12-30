struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val): key(key),val(val),next(NULL),prev(NULL){}
};

class LRUCache {
public:
    unordered_map<int,Node*> umap;
    int capacity;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;
        Node* node=umap[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end()){
            Node* oldnode=umap[key];
            remove(oldnode);
        }
        Node* output=new Node(key,value);
        umap[key]=output;
        add(output);
        if(umap.size()>capacity){
            Node* nodedel=head->next;
            remove(nodedel);
            umap.erase(nodedel->key);
        }
    }
    void remove(Node* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }

    void add(Node* node){
        Node* prevnode=tail->prev;
        prevnode->next=node;
        node->prev=prevnode;
        node->next=tail;
        tail->prev=node;
    }  
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */