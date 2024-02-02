class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> umap;
        for(auto i:s) umap[i]++;
        for(auto i:t) umap[i]--;

        for(auto it:umap){
            if(it.second!=0) return false;
        }
        return true;
    }
};