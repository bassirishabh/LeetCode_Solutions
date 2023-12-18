class Solution {
public:
    int myAtoi(string s) {
        int answer=0;

        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        if(i==s.size()) return answer;
        int sign=1;;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(i<s.size() && isdigit(s[i])){
            if((answer>INT_MAX/10) || (answer==INT_MAX/10 && (s[i]-'0')>INT_MAX%10)) return sign==1?INT_MAX:INT_MIN;

            answer=answer*10+(s[i]-'0');
           
            i++;
        }
        return sign*answer;

    }
};