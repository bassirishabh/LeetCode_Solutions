class Solution {
public:
    string expand(string s, int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        string maxstr="";
        for(int i=0;i<s.size()-1;i++){
            string odd=expand(s,i,i);

            string even=expand(s,i,i+1);
            cout<<i<<" "<<odd<<" "<<even;
            if(odd.size()>maxstr.size()){
                maxstr=odd;
            }
            if(even.size()>maxstr.size()){
                maxstr=even;
            }
        }
        return maxstr;
    }
};