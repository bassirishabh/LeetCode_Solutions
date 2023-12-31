class Solution {
public:
    string minWindow(string s, string t) {
        int lens=s.length();
        int lent=t.length();
        if(s.empty() || t.empty()) return "";
        int formed=0;
        int minlen=INT_MAX;
        unordered_map<char,int> umaps;
        unordered_map<char,int> umapt;

        for(auto i:t) umapt[i]++;
        int l=0;
        int r=0;
        int lans=0;
        int rans=0;
        while(r<lens){
            umaps[s[r]]++;
            if(umapt.find(s[r])!=umapt.end() && umapt[s[r]]==umaps[s[r]]) formed+=1;

            while(l<=r && formed==umapt.size()){
                char c=s[l];
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    lans=l;
                    rans=r;
                }
                umaps[s[l]]-=1;
                if(umapt.find(s[l])!=umapt.end() && umaps[s[l]]<umapt[s[l]]) formed-=1;
                l+=1;
            }
            r+=1;
        }
        return (minlen==INT_MAX)?"":s.substr(lans,rans-lans+1);


    }
};