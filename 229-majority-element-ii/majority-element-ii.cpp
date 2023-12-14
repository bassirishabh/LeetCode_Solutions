class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto it:nums){
            umap[it]++;
        }
        vector<int> result;
        for(auto it:umap){
            if(it.second>nums.size()/3) result.push_back(it.first);
        }
        return result;
    }
};