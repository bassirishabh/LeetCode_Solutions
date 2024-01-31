class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i=0;i<9;i++){
            rows[i]=unordered_set<char>();
            cols[i]=unordered_set<char>();
            boxes[i]=unordered_set<char>();
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char ch=board[i][j];
                if(ch=='.') continue;
                if(rows[i].count(ch)>0) return false;
                rows[i].insert(ch);
                if(cols[j].count(ch)>0) return false;
                cols[j].insert(ch);
                int index=(i/3)*3+(j/3);
                if(boxes[index].count(ch)>0) return false;
                boxes[index].insert(ch);
            }
        }
        return true;
    }
};