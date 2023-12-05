class Solution {
public:
    int rows;
    int cols;

    int orangesRotting(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int fresh=0;
        vector<vector<int>> visited=grid;
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        if(q.empty()) return -1;

        int time=-1;
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();
                q.pop();
                for(auto pa:dirs){
                    int i=p.first+pa.first;
                    int j=p.second+pa.second;
                    if(i>=0 && i<rows && j>=0 && j<cols && visited[i][j]==1){
                        visited[i][j]=2;
                        fresh--;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }
        if(fresh==0) return time;
        return -1;
    }
};