class Solution {
public:
    int reverse(int x) {
        int n=x;

        long long reversenumber=0;

        while(x){
          reversenumber=reversenumber*10+(x%10);
          x=x/10;
        }
        if(reversenumber<=INT_MIN || reversenumber>=INT_MAX-1) return 0;
        return (int)reversenumber;
    }
};