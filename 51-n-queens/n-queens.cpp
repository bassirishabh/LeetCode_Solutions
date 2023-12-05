class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> cols,diag,antidiag;

    void backtrack(int index,int n,vector<string> tmp){
        if(index==n){
            result.push_back(tmp);
            return;
        }

        string str(n,'.');
        for(int col=0;col<n;col++){
            if(cols.count(col) || diag.count(index-col) || antidiag.count(index+col)) continue;
            cols.insert(col);
            diag.insert(index-col);
            antidiag.insert(index+col);
            str[col]='Q';
            tmp.push_back(str);
            backtrack(index+1,n,tmp);
            tmp.pop_back();
            str[col]='.';
            cols.erase(col);
            diag.erase(index-col);
            antidiag.erase(index+col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        backtrack(0,n,{});
        return result;
    }
};