class Solution {
public:
    int solve(string s,int sign,int i,long long result){
        if(sign*result>=INT_MAX) return INT_MAX;
        if(sign*result<=INT_MIN) return INT_MIN;

        if(s[i]==' '|| !isdigit(s[i])) return result*sign;
        int sol=s[i]-'0';
        return solve(s,sign,i+1,result*10+sol);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        int sign=1;
        int flag=0;
        if(s[i]=='-'){
            sign=-1;
            i++;
            flag++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
            flag++;
        }
        if(flag>1) return 0;
        return solve(s,sign,i,0);
    }
};