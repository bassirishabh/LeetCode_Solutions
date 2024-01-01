class Solution {
public:
    int rows;
    int cols;

    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]!='O') return;
        board[i][j]='*';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
         rows=board.size();
        cols=board[0].size();

        for(int i=0;i<rows;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][cols-1]=='O') dfs(board,i,cols-1);
        }
        for(int i=0;i<cols;i++){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[rows-1][i]=='O') dfs(board,rows-1,i);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='*') board[i][j]='O';
            }
        }

    }
};