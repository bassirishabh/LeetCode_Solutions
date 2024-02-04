class Solution {
public:
    double power(double x, long long n){
        if(n<0){
            n=-1*n;
            x=(1.0/x);
        }
        double result=1;
        while(n>0){
            if(n%2==0){
                x=x*x;
                n=n>>1;
            }else{
                result=result*x;
                n-=1;
            }  
        }
        return result;
        


    }
    double myPow(double x, int n) {
        return power(x,(long long)n);
    }
};