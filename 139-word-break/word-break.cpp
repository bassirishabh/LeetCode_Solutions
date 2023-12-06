class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),0);

        for(int i=0;i<s.size();i++){
            for(auto w:wordDict){
                if(i<w.length()-1) continue;
                if(i==w.length()-1 || dp[i-w.length()]){
                    if(s.substr(i-w.length()+1,w.length())==w){
                        dp[i]=1;
                    }
                }
                
            }
        }
        return dp[s.size()-1];
        
    }
};