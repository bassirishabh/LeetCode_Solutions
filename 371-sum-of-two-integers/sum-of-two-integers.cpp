class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
        int carry=a&b;
        int actualcarry=carry<<1;
        while(carry!=0){
          carry=actualcarry&sum;
          sum=sum^actualcarry;
          actualcarry=carry<<1;
        }
        return sum;
    }
};