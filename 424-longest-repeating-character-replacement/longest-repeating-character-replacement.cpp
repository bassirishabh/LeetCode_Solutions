class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqmap(26,0);

        int left=0;
        int right=0;
        int maxfreq=0;
        int maxlen=0;
        while(right<s.size()){
            freqmap[s[right]-'A']++;
            maxfreq=max(maxfreq,freqmap[s[right]-'A']);
            while((right-left+1-maxfreq)>k){
                freqmap[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;


    }
};