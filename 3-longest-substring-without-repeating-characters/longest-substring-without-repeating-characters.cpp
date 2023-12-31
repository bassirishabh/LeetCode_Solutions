class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;

        int left=0;
        int right=0;

        int maxlen=0;
        while(right<s.size()){
            umap[s[right]]++;
            while(umap[s[right]]>1){
                umap[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};