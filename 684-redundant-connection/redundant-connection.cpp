class Solution {
public:
    int find_parent(int node,vector<int>& parent){
        if(node==parent[node]) return node;
        return parent[node]=find_parent(parent[node],parent);
    }
    void union_find(int u,int v,vector<int>& parent,vector<int>& rank ){
        u=find_parent(u,parent);
        v=find_parent(v,parent);

        if(rank[u]>rank[v]){
            parent[v]=u;
        }else if(rank[v]>rank[u]){
            parent[u]=v;
        }else{
            parent[v]=u;
            rank[u]+=1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1,0);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int> ans(2,0);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            if(find_parent(u,parent)!=find_parent(v,parent)){
                union_find(u,v,parent,rank);
            }else if(find_parent(u,parent)==find_parent(v,parent)){
                ans[0]=u;
                ans[1]=v;
            }
        }
        return ans;
    }
};