class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj(n);

      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
      pq.push({0,src,0});

      for(auto e:flights){
        adj[e[0]].push_back({e[1],e[2]});
      }
      vector<int> stops(n,INT_MAX);
      while(!pq.empty()){
        auto tp=pq.top();
        pq.pop();
        int dist=tp[0];
        int node=tp[1];
        int steps=tp[2];

        if(stops[node]<steps || steps>k+1) continue;
        stops[node]=steps;
        if(node==dst) return dist;
        for(auto e:adj[node]){
          pq.push({dist+e.second,e.first,steps+1});
        }
      }
        return -1;
    }
};