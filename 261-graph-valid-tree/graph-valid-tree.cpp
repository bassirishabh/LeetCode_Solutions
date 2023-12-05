class Solution {
public:

    void dfs(vector<vector<int>>& adj,set<int>& seen,int i){
        if(seen.count(i)) return;
        seen.insert(i);
        for(auto nei:adj[i]) dfs(adj,seen,nei);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        set<int> node;
        if(edges.size()!=n-1) return false;

        for(auto p:edges){
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
        }

        dfs(adj,node,0);
        return node.size()==n;
    }
};