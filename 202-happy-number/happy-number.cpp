class Solution {
public:
    int getnext(int n){
        int result=0;

        while(n){
            result+=(n%10)*(n%10);
            n=n/10;
        }
        return result;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=getnext(n);

        while(fast!=1 && slow!=fast){
            slow=getnext(slow);
            fast=getnext(getnext(fast));
        }
        return (fast==1)?true:false;
    }
};