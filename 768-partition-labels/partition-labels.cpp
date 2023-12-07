class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> umap;

        for(int i=0;i<s.size();i++){
          umap[s[i]]=i;
        }
        vector<int> result;
        int size=0,end=0;
        for(int i=0;i<s.size();i++){
          size++;
          end=max(end,umap[s[i]]);
          if(i==end){
            result.push_back(size);
            size=0;
          }
        }
        return result;
    }
};