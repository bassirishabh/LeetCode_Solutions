class Solution {
public:
    int minDistance(string word1, string word2) {
         int w1len=word1.size();
        int w2len=word2.size();

        if(w1len==0) return w2len;
        if(w2len==0) return w1len;

        vector<vector<int>> dp(w1len+1,vector<int>(w2len+1,0));
        for(int i=0;i<=w1len;i++) dp[i][0]=i;
        for(int i=0;i<=w2len;i++) dp[0][i]=i;

        for(int i=1;i<=w1len;i++){
            for(int j=1;j<=w2len;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[w1len][w2len];
    }
};