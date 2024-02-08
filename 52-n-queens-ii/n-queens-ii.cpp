class Solution {
public:
    int backtrack(int row,int n,unordered_set<int> cols,unordered_set<int> diag,unordered_set<int> antidiag){
        int solutions=0;
        if(row==n) return 1;

        for(int col=0;col<n;col++){
            if(cols.count(col)||diag.count(row-col)||antidiag.count(row+col)) continue;
            cols.insert(col);
            diag.insert(row-col);
            antidiag.insert(row+col);
            solutions+=backtrack(row+1,n,cols,diag,antidiag);
            cols.erase(col);
            diag.erase(row-col);
            antidiag.erase(row+col);

        }
        return solutions;

    }
    int totalNQueens(int n) {
        return backtrack(0,n,unordered_set<int>(),unordered_set<int>(),unordered_set<int>());
    }
};