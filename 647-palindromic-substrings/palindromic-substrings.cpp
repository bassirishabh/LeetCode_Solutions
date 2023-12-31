class Solution {
public:
    int countSubstrings(string s) {
      int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));

        int ans=0;
        for(int diff=0;diff<n;diff++){
          for(int i=0,j=i+diff;j<n;i++,j++){
            if(i==j) dp[i][j]=1;
            else if(diff==1) dp[i][j]=(s[i]==s[j])?1:0;
            else{
              if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            }
            ans+=dp[i][j];
          }
        }
        return ans;
    }
};