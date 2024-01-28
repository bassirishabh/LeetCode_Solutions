class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j<n;j++){
                if(strs[j][i]!=strs[0][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};