class Solution {
public:
    vector<string> result;

    void backtrack(int left,int right,int n, string s){
        if(s.size()==2*n){
            result.push_back(s);
            return;
        }
        if(left<n){
            s.push_back('(');
            backtrack(left+1,right,n,s);
            s.pop_back();
        }
        if(left>right){
            s.push_back(')');
            backtrack(left,right+1,n,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n,"");
        return result;
    }
};