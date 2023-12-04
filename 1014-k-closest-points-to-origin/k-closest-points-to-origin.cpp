class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> result;

        for(auto p:points){
            pq.push({(p[0]*p[0])+(p[1]*p[1]),p});
            if(pq.size()>k) pq.pop();
        }
        while(pq.size()>0){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};