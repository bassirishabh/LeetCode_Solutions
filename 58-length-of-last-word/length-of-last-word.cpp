class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int len=0;

        while(n>=0){
            if(s[n]!=' '){
                len++;
            }else if(len>0){
                return len;
            }
            n--;
        }
        return len;
    }
};