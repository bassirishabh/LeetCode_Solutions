class Solution {
public:
    vector<vector<string>> result;

    void backtrack(string s, int index, vector<string> temp){
        if(index==s.size()){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isvalid(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                backtrack(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    bool isvalid(string s, int left,int right){
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0,{});
        return result;
    }
};