class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        vector<int> sorted_queries = queries;
        sort(intervals.begin(),intervals.end());
        sort(sorted_queries.begin(),sorted_queries.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        unordered_map<int,int> umap;
        int i=0,left,right;
        for(int j=0;j<sorted_queries.size();j++){
          int q=sorted_queries[j];
          while(i<n && q>=intervals[i][0]){
            left=intervals[i][0];
            right=intervals[i][1];
            pq.push({right-left+1,right});
            i++;
          }

          while(!pq.empty() && pq.top().second<q) pq.pop();
          if(!pq.empty()) umap[q]=pq.top().first;
          else umap[q]=-1;
        }
        for(auto x:queries) ans.push_back(umap[x]);
        return ans;
    }
};