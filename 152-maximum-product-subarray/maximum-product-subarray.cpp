class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod=nums[0];
        int maxprod=nums[0];
        int ans=maxprod;
        for(int i=1;i<nums.size();i++){
            int tempmax=maxprod;
            maxprod=max(nums[i],max(nums[i]*maxprod,nums[i]*minprod));
            minprod=min(nums[i],min(nums[i]*tempmax,nums[i]*minprod));
            ans=max(ans,maxprod);
        }
        return ans;
    }
};