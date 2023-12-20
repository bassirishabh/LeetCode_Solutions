class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]++;
        }
        for(auto it:umap){
            if(it.second>=2) return true;
        }
        return false;
    }
};