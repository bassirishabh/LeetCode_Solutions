class Solution {
public:
    unordered_map<int,int> memo;

    int decode(string s, int index){
        if(memo.find(index)!=memo.end()) return memo[index];
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;

        int ans=decode(s,index+1);
        if(index + 1 < s.size() && stoi(s.substr(index,2))<=26){
            ans+=decode(s,index+2);
        }
        return memo[index]=ans;
    }
    int numDecodings(string s) {
        return decode(s,0);
    }
};