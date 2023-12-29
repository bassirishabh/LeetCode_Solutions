class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isneg=false;

        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) isneg=true;
        long long div=abs(dividend);
        long long divis=abs(divisor);

        long result=0;
        while(div>=divis){
            long tmp=divis,count=1;
            while(tmp<=div){
                tmp<<=1;
                count<<=1;

            }
            result+=count>>1;
            div-=tmp>>1;
        }
        
        return  isneg ?  ~result + 1 : result > INT_MAX ? INT_MAX : (int) result;
    }
};