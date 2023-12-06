class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);

        for(int i=2;i<dp.size();i++){
          int takeone=dp[i-1]+cost[i-1];
          int taketwo=dp[i-2]+cost[i-2];        
          dp[i]=min(takeone,taketwo);
        }
        return dp[cost.size()];
    }
};