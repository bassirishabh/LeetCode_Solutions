class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]++;
        }
        for(auto it:umap){
            pq.push({it.second,it.first});
        }
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;

    }
};