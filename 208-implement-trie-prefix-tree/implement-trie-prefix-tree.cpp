struct TrieNode{
    unordered_map<char,TrieNode*> children;
    bool endofword=false;
};
class Trie {
public:
    TrieNode* root=new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c]=new TrieNode();
            }
            node=node->children[c];
        }
        node->endofword=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(auto c:word){
            if(node->children.find(c)==node->children.end()) return false;
            node=node->children[c];
        }
        return node->endofword;
    
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(auto c:prefix){
            if(node->children.find(c)==node->children.end()) return false;
            node=node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */