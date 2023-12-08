class Solution {
public:
    int recurse(vector<int>& nums,int i,int j,vector<vector<int>> &dp){
        if(j-i<0) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int result=0;
        for(int left=i;left<=j;left++){
            int gain=nums[i-1]*nums[left]*nums[j+1];
            int remain=recurse(nums,i,left-1,dp)+recurse(nums,left+1,j,dp);
            result=max(result,remain+gain);
        }
        dp[i][j]=result;
        return result;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        return recurse(nums,1,nums.size()-2,dp);
        
    }
};