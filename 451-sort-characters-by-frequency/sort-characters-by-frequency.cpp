class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> umap;

        for(auto i:s){
            umap[i]++;
        }
        string s1="";
        vector<pair<char,int>> v;
        for(auto i:umap){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i:v){
            for(int j=1;j<=i.second;j++){
                s1+=i.first;
            }
            
        }
        return s1;
    }
};