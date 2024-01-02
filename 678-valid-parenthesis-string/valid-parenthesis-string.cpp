class Solution {
public:
    bool checkValidString(string s) {
        int leftmin=0,leftmax=0;

        for(auto i:s){
            if(i=='('){
                leftmin+=1;
                leftmax+=1;
            }
            else if(i==')'){
                leftmin-=1;
                leftmax-=1;
            }
            else{
                leftmin-=1;
                leftmax+=1;
            }
            if(leftmax<0) return false;
            if(leftmin<0) leftmin=0;
        }
        return leftmin==0;
    }
};