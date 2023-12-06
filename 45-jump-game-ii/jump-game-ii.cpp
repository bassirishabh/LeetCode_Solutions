class Solution {
public:
    int jump(vector<int>& nums) {
        int right=0;
        int left=0;
        int maxfar=0;
        int result=0;
        while(right<nums.size()-1){
          for(int i=left;i<=right;i++){
            maxfar=max(maxfar,i+nums[i]);
          }
          left=right;
          right=maxfar;
          result+=1;
        }
        return result;
    }
};