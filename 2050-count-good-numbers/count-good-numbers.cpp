
#define mod 1000000007
class Solution {
public:
    long long power(long long x,long long n){
        if(n==0) return 1;

        if(n%2==0){
            return power((x*x)%mod,n/2);
        }else{
            return (x*power(x,n-1))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long oddplaces=n/2;
        long long evenplaces=n-oddplaces;
        return (power(5,evenplaces)*power(4,oddplaces))%mod;
    }
};