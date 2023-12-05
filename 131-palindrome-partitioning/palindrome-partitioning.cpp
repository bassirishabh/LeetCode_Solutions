class Solution {
public:
    vector<vector<string>> result;

    void backtrack(string s, vector<string> curr,int index){
        if(index>=s.size()){
            result.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isvalid(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                backtrack(s,curr,i+1);
                curr.pop_back();
            }
            
        }
    }
    bool isvalid(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,{},0);
        return result;
    }
};