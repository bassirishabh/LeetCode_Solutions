class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> umap;

        for(auto i:magazine) umap[i]++;
        for(auto i:ransomNote){
            if(umap[i]<=0) return false;
            umap[i]--;
        }
        return true;
    }
};