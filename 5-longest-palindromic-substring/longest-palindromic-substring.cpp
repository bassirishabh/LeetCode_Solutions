class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        string ans="";
        int maxlen=0;
        for(int diff=0;diff<s.length();diff++){
          for(int i=0,j=i+diff;j<s.length();i++,j++){
            if(i==j) dp[i][j]=1;
            else if(diff==1) dp[i][j]=(s[i]==s[j])?2:0;
            else{
              if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=2+dp[i+1][j-1];
            }
            if(dp[i][j]){
              if(j-i+1>maxlen){
                maxlen=j-i+1;
                ans=s.substr(i,maxlen);
              }
            }
          }
        }
        return ans;
    }
};