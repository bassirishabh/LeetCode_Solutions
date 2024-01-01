class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> numdegrees(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            numdegrees[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(numdegrees[i]==0){
                q.push(i);
            }
        }
        int visit=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visit++;
            for(auto n:adj[node]){
                numdegrees[n]--;
                if(numdegrees[n]==0) q.push(n);
            }
        }
        return (visit==numCourses);
    }
};