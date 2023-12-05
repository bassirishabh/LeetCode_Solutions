class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegrees[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto a:adj[node]){
                indegrees[a]--;
                if(indegrees[a]==0) q.push(a);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};