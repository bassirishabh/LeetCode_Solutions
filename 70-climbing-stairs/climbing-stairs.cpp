class Solution {
public:
    int climbStairs(int n) {
      if(n==1) return 1;
      int first=1;
      int second=2;

      for(int third=3;third<=n;third++){
        int a=first+second;
        first=second;
        second=a;
      }
      return second;
        
    }
};