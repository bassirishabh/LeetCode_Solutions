class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;

        int i=0;
        int j=0;
        int maxlen=0;
        while(i<s.size()){
            umap[s[i]]++;
            while(umap[s[i]]>1){
                umap[s[j]]--;
                j++;
            }
            maxlen=max(maxlen,i-j+1);
            i++;
        }
        return maxlen;
    }
};