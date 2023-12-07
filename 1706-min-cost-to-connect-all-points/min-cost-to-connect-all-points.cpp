class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n=points.size();

      int mstcost=0;
      int numedges=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      vector<int> mst(n,0);
      pq.push({0,0});
      while(numedges<n){
        auto topele=pq.top();
        pq.pop();

        int wt=topele.first;
        int curnode=topele.second;

        if(mst[curnode]) continue;
        mst[curnode]=1;
        mstcost+=wt;
        numedges++;

        for(int nxt=0;nxt<n;nxt++){
          if(!mst[nxt]){
            int nxtwt=abs(points[curnode][0]-points[nxt][0])+abs(points[curnode][1]-points[nxt][1]);
            pq.push({nxtwt,nxt});
          }
        }
      }
        return mstcost;
    }
};