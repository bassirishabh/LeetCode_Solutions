class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> charS(128,0);
        vector<int> charT(128,0);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(charS[s[i]]!=charT[t[i]]) return false;
            charS[s[i]]=i+1;
            charT[t[i]]=i+1;
        }
        return true;
    }
};