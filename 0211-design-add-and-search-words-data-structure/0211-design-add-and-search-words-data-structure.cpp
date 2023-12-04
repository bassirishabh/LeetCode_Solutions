struct TrieNode{
    unordered_map<char,TrieNode*> children;
    bool endofword=false;
};

class WordDictionary {
public:
    TrieNode* root=new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(auto c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c]=new TrieNode();
            }
            node=node->children[c];
        }
        node->endofword=true;
    }
    
    bool searchelper(string word, TrieNode* node, int index){
        for(int i=index;i<word.size();i++){
            if(word[i]=='.'){
                for(auto p:node->children){
                    if(searchelper(word,p.second,i+1)) return true;
                }
                return false;
            }else{
                if(node->children.find(word[i])==node->children.end()) return false;
                node=node->children[word[i]];
            } 
        }
        return node->endofword;
    }
    bool search(string word) {
        return searchelper(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */