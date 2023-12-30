class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key)==umap.end()) return "";
        if(timestamp<umap[key][0].first) return "";

        int left=0;
        int right=umap[key].size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(umap[key][mid].first<=timestamp){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(right==-1) return "";
        return umap[key][right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */