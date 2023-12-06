class Solution {
public:
    int solve(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev;
            int ans=max(take,nottake);
            prev2=prev;
            prev=ans;

        }
        return prev;
        
    }
    int rob(vector<int>& nums) {
        vector<int> first,last;
        int ans=0;
        if(nums.size()==1) return nums[0];

        for(int i=0;i<nums.size();i++){
            if(i!=0) last.push_back(nums[i]);
            if(i!=nums.size()-1) first.push_back(nums[i]);
        }
        ans=max(solve(first),solve(last));
        return ans;
    }
};