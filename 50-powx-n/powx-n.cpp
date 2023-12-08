class Solution {
public:
    double expo(double x,long long n){
        if(n<0){
            x=1.0/x;
            n=-1*n;
        }
        double result=1;
        while(n>0){
            if(n%2==1){
                result=result*x;
                n-=1;
            }
                x=x*x;
                n=n>>1;
            
        }
        return result;
    }
    double myPow(double x, int n) {
        return expo(x,(long long)n);
    }
};