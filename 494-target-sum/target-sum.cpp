class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2*total + 1, 0));
        dp[0][nums[0]+total]=1;
        dp[0][-nums[0]+total]+=1;

        for(int i=1;i<nums.size();i++){
          for(int sum=-total;sum<=total;sum++){
            if(dp[i-1][sum+total]>0){
              dp[i][sum+nums[i]+total]+=dp[i-1][sum+total];
              dp[i][sum-nums[i]+total]+=dp[i-1][sum+total];
            }
          }
        }
        return abs(target)>total?0:dp[nums.size()-1][target+total];
    }
};