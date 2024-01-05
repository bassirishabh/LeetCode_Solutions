class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto f:times){
            adj[f[0]].push_back({f[1],f[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int adjnode=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            for(auto it:adj[adjnode]){
                int adj=it.first;
                int edW=it.second;
                if(wt+edW<dist[adj]){
                    dist[adj]=wt+edW;
                    pq.push({wt+edW,adj});
                }
            }

        }
        int mini = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            if(i!=k and dist[i]==INT_MAX)
            {
                return -1;
            }
            
            mini = max(mini,dist[i]);
            
        }
                               
        return mini;
    }
};