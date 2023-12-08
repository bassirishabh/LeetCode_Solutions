class Solution {
public:
    int stock(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
      
      if(index>=prices.size()) return 0;
      if(dp[index][buy]!=-1) return dp[index][buy];
      if(buy==1){
        return dp[index][buy]=max(-prices[index]+stock(index+1,0,prices,dp),0+stock(index+1,1,prices,dp));
      }else{
        return dp[index][buy]=max(prices[index]+stock(index+2,1,prices,dp),0+stock(index+1,0,prices,dp));
      }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return stock(0,1,prices,dp);
    }
};