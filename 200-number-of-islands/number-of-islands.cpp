class Solution {
public:
    int rows;
    int cols;
    void dfs(int i,int j,vector<vector<char>>& grid){
      if(i<0 || i>=rows || j<0 ||j>=cols || grid[i][j]=='0') return;

      grid[i][j]='0';
      dfs(i+1,j,grid);
      dfs(i-1,j,grid);
      dfs(i,j+1,grid);
      dfs(i,j-1,grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int numislands=0;
        for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
            if(grid[i][j]=='1'){
              numislands++;
              dfs(i,j,grid);
            }
          }
        }
        return numislands;
    }
};