class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int num:nums) totalsum+=num;

        if(totalsum%2!=0) return false;
        int subsetsum=totalsum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(subsetsum+1,false));

        dp[0][0]=true;
        for(int i=1;i<=n;i++){
          int curr=nums[i-1];
          for(int j=0;j<=subsetsum;j++){
            if(j<curr) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j] || dp[i-1][j-curr];
          }
        }
        return dp[n][subsetsum];

    }
};