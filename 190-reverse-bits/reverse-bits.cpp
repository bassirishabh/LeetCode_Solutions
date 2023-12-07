class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int power=31;
        int res=0;
        while(n){
          res|=(n&1)<<power;
          power-=1;
          n=n>>1;
        }
        return res;
    }
};