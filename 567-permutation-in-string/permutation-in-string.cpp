class Solution {
public:
    bool areequal(vector<int> freqmap1,vector<int> freqmap2){
        for(int i=0;i<26;i++){
            if(freqmap1[i]!=freqmap2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> freqmap1(26,0);
        vector<int> freqmap2(26,0);

        for(auto i:s1){
            freqmap1[i-'a']++;
        }
        int i=0;
        int j=0;
        while(j<s2.size()){
            freqmap2[s2[j]-'a']++;
            if(j-i+1==s1.size()){
                if(areequal(freqmap1,freqmap2)) return true;
            }
            if(j-i+1<s1.size()) j++;
            else{
                freqmap2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};