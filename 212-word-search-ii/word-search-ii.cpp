class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    bool endofword=false;

    void insert(string word){
        TrieNode* root=this;
        for(auto c:word){
            if(root->children.find(c)==root->children.end()){
                root->children[c]=new TrieNode();
            }
            root=root->children[c];
        }
        root->endofword=true;
    }
};


class Solution {
public:
    int rows;
    int cols;
    vector<string> result;

    void backtrack(int i,int j,vector<vector<char>>& board, vector<string>& words,TrieNode* root,string word){
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]=='#') return;
        char ch=board[i][j];
        if(root->children.find(ch)==root->children.end()) return;
        word.push_back(ch);
        root=root->children[ch];
        if(root->endofword){
            result.push_back(word);
            root->endofword=false;
        }
        board[i][j]='#';
        backtrack(i+1,j,board,words,root,word);
        backtrack(i-1,j,board,words,root,word);
        backtrack(i,j+1,board,words,root,word);
        backtrack(i,j-1,board,words,root,word);
        board[i][j]=ch;
        word.pop_back();

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows=board.size();
        cols=board[0].size();
        TrieNode* root=new TrieNode();
        for(auto c:words){
            root->insert(c);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                backtrack(i,j,board,words,root,"");
            }
        }
        return result;
    }
};