class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<vector<int>> dist(n,vector<int>(n,1e9));

      dist[0][0]=grid[0][0];

      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      pq.push({grid[0][0],{0,0}});
      vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
      while(!pq.empty()){
        auto tp=pq.top();
        pq.pop();
        int cost=tp.first;
        int row=tp.second.first;
        int col=tp.second.second;
        int maxi=INT_MIN;
        for(auto d:dir){
          int newrow=row+d.first;
          int newcol=col+d.second;
          if(newrow>=0 && newrow<n && newcol>=0 && newcol<n){
            maxi=max(cost,grid[newrow][newcol]);
            if(dist[newrow][newcol]>maxi){
              dist[newrow][newcol]=maxi;
              pq.push({maxi,{newrow,newcol}});
            }
          }
        }

      }
        return dist[n-1][n-1];
    }
};