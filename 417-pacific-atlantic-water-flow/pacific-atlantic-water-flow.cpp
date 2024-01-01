class Solution {
public:
 int rows;
    int cols;

    void dfs(int i,int j,vector<vector<int>>& visited,int prevheight,vector<vector<int>>& heights){
        if(i<0 || i>=rows || j<0 || j>=cols || visited[i][j] || heights[i][j]<prevheight) return;

        visited[i][j]=1;
        dfs(i+1,j,visited,heights[i][j],heights);
        dfs(i-1,j,visited,heights[i][j],heights);
        dfs(i,j+1,visited,heights[i][j],heights);
        dfs(i,j-1,visited,heights[i][j],heights);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         rows=heights.size();
        cols=heights[0].size();

        vector<vector<int>> atl(rows,vector<int>(cols,0));
        vector<vector<int>> pac(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            dfs(i,0,pac,heights[i][0],heights);
            dfs(i,cols-1,atl,heights[i][cols-1],heights);
        }
        for(int i=0;i<cols;i++){
            dfs(0,i,pac,heights[0][i],heights);
            dfs(rows-1,i,atl,heights[rows-1][i],heights);
        }
        vector<vector<int>> result;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(atl[i][j] && pac[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};