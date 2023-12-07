class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        int m = text1.length();
        int n = text2.length();
        int k = max(m,n);
        vector<int> prev(k+1,0), cur(k+1,0);
        for(int i=1;i<=text1.length();i++){
          for(int j=1;j<=text2.length();j++){
            if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
            else cur[j]=max(prev[j],cur[j-1]);
          }
          prev=cur;
        }
        return prev[n];
    }
};