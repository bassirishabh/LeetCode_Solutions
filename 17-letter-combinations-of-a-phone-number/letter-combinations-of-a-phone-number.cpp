class Solution {
public:
    vector<string> result;
    unordered_map<char,string> umap;
    void backtrack(string digits,string curr,int index){
        if(curr.size()==digits.size()){
            result.push_back(curr);
            return;
        }
        for(auto c:umap[digits[index]]){
            curr+=c;
            backtrack(digits,curr,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        umap['2']="abc";
        umap['3']="def";
        umap['4']="ghi";
        umap['5']="jkl";
        umap['6']="mno";
        umap['7']="pqrs";
        umap['8']="tuv";
        umap['9']="wxyz";
        backtrack(digits,{},0);
        return result;
    }
};