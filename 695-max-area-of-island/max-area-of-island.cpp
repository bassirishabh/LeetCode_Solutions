class Solution {
public:int rows;
    int cols;

    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==0) return 0;
        grid[i][j]=0;
        return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1)+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> grid1=grid;
        rows=grid1.size();
        cols=grid1[0].size();
        int mi=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid1[i][j]==1){
                    mi=max(mi,dfs(grid1,i,j));
                }
            }
        }
        return mi;
    }
};