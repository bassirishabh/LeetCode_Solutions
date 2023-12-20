class Solution {
public:
    int solve(string s, int sign,int i, long long result){
        if(result*sign>=INT_MAX) return INT_MAX;
        if(result*sign<=INT_MIN) return INT_MIN;

        if(s[i]==' ' || !isdigit(s[i])) return sign*result;

        int digit=s[i]-'0';
        return solve(s,sign,i+1,result*10+digit);
    }
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        int flag=0;
        while(i<s.size() && s[i]==' ') i++;

        if(s[i]=='-'){
            sign=-1;
            flag++;
            i++;
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