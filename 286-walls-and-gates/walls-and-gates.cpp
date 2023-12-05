class Solution {
public:
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows=rooms.size();
        int cols=rooms[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto pa:directions){
                int r=p.first+pa.first;
                int c=p.second+pa.second;
                if(r>=0 && r<rows && c>=0 && c<cols && rooms[r][c]==INT_MAX){
                    rooms[r][c]=1+rooms[p.first][p.second];
                    q.push({r,c});
                }
            }


        }
    }
};