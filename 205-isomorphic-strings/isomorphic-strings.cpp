class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> sM,tM;
        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            if(sM.find(s[i])!=sM.end() && sM[s[i]]!=t[i]) return false;
            if(tM.find(t[i])!=tM.end() && tM[t[i]]!=s[i]) return false;
            sM[s[i]]=t[i];
            tM[t[i]]=s[i];
        }
        return true;
    }
};