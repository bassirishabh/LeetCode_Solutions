class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> numdegrees(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> result;

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

        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto ad:adj[node]){
                numdegrees[ad]--;
                if(numdegrees[ad]==0) q.push(ad);
            }
        }
        if(result.size()==numCourses) return result;
        return {};
    }
};