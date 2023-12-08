class Solution {
public:
    int rows;
    int cols;
    int ans=0;
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=0) return dp[i][j];
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        for(auto p:dir){
            int nr=i+p.first;
            int nc=j+p.second;
            if(nr>=0 && nr<rows && nc>=0 && nc<cols && matrix[nr][nc]>matrix[i][j]){
                dp[i][j]=max(dp[i][j],dfs(matrix,nr,nc,dp));
            }
        }
        dp[i][j]+=1;
        return dp[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows=matrix.size();
        cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans=max(ans,dfs(matrix,i,j,dp));
            }
        }
        return ans;
    }
};