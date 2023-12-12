class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        umap[0]=1;
        int sum=0;
        int count=0;
        for(auto i:nums){
            sum+=i;
            if(umap.find(sum-k)!=umap.end()) count+=umap[sum-k];
            umap[sum]+=1;
        }
        return count;
        
    }
};