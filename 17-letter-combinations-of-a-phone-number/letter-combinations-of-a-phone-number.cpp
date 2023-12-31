class Solution {
public:
    unordered_map<char,string> umap;
    vector<string> result;

    void backtrack(string digits,int index, string temp){
        if(temp.size()==digits.size()){
            result.push_back(temp);
            return;
        }
        for(auto c:umap[digits[index]]){
            temp+=c;
            backtrack(digits,index+1,temp);
            temp.pop_back();
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

        backtrack(digits,0,"");
        return result;

    }
};