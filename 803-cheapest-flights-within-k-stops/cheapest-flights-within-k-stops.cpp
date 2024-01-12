class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int stops=node.first;
            int nd=node.second.first;
            int cost=node.second.second;
            if(stops>k) continue;
            for(auto it:adj[nd]){
                int nxt=it.first;
                int edW=it.second;
                if(cost+edW<dist[nxt] && stops<=k){
                    dist[nxt]=cost+edW;
                    q.push({stops+1,{nxt,dist[nxt]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};