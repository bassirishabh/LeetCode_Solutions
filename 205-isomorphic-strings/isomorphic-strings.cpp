class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> sM(128,0);
        vector<char> tM(128,0);
        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            if(sM[s[i]]!=tM[t[i]]) return false;
            
            sM[s[i]]=i+1;
            tM[t[i]]=i+1;
        }
        return true;
    }
};