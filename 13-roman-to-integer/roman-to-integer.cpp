class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> umap;
        umap['I']=1;
        umap['V']=5;
        umap['X']=10;
        umap['L']=50;
        umap['C']=100;
        umap['D']=500;
        umap['M']=1000;

        int answer=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && umap[s[i]]<umap[s[i+1]]){
                answer+=umap[s[i+1]]-umap[s[i]];
                i++;
            }else{
                answer+=umap[s[i]];
            }

        }
        return answer;
    }
};