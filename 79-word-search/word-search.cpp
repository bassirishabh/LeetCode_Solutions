class Solution {
public:
    int rows;
    int cols;
    
    bool backtrack(int i,int j,vector<vector<char>>& board, string word,int index){
        if(index==word.size()) return true;
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]!=word[index]) return false;
        
        char ch=board[i][j];
        board[i][j]='#';

        bool result=backtrack(i+1,j,board,word,index+1) || backtrack(i-1,j,board,word,index+1)|| backtrack(i,j+1,board,word,index+1)|| backtrack(i,j-1,board,word,index+1);
        board[i][j]=ch;
        return result;


    }
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(backtrack(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};