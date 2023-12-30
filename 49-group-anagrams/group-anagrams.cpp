class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> umap;
        for(auto i:strs){
            string t=i;
            sort(t.begin(),t.end());
            umap[t].push_back(i);
        }
        for(auto i:umap){
            result.push_back(i.second);
        }
        return result;
    }
};