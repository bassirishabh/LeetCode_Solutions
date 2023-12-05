class Solution {
public:
    void dfs(int i,vector<int>& visited,vector<vector<int>>& adj){
        visited[i]=1;
        for(auto ad:adj[i]){
            if(visited[ad]==0) dfs(ad,visited,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);
        int count=0;
        for(auto p:edges){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,visited,graph);
            }
        }
        return count;
    }
};