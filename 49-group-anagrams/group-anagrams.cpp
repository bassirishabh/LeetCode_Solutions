class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> umap;
        for(auto i:strs){
            string s=i;
            sort(i.begin(),i.end());
            umap[i].push_back(s);
        }
        for(auto it:umap){
            result.push_back(it.second);
        }
        return result;
    }
};