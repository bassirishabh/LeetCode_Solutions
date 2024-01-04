class Solution {
public:
    bool subset(vector<int> nums, int targetsum){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(targetsum+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        // if (nums[0] <= targetsum)
        //     dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=targetsum;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                dp[i][target]=take || nottake;
            }
        }
        return dp[n-1][targetsum];
    }
    bool canPartition(vector<int>& nums) {
        int targetsum=0;
        for(auto i:nums){
            targetsum+=i;
        }
        if (targetsum % 2 == 1) return false;
        return subset(nums,targetsum/2);
    }
};