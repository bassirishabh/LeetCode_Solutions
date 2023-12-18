class Solution {
public:
    int beautySum(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> umap;
            for(int j=i;j<n;j++){
                umap[s[j]]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(auto it:umap){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                count+=(maxi-mini);
            }
            umap.clear();
        }
        return count;
    }
};