class Solution {
public:

    int recurse(string s, string t,int i,int j,vector<vector<int>>& dp){

        if(i==s.size() || j==t.size()){
            return j==t.size()?1:0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) dp[i][j]=(recurse(s,t,i+1,j,dp)+recurse(s,t,i+1,j+1,dp));
        else dp[i][j]=recurse(s,t,i+1,j,dp);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return recurse(s,t,0,0,dp);
    }
};