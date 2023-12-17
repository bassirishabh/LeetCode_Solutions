class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        string result="";
        int maxlen=0;
        for(int diff=0;diff<s.size();diff++){
            for(int i=0,j=i+diff;j<s.size();i++,j++){
                if(i==j) dp[i][j]=1;
                else if(diff==1) dp[i][j]=(s[i]==s[j])?2:0;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j]){
                    if(maxlen<j-i+1){
                        maxlen=j-i+1;
                        result=s.substr(i,maxlen);
                    }
                }
            }
        }
        return result;
    }
};