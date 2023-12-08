class Solution {
public:

    int calculate(vector<int>& nums, int target,int i,long long total){
      if(i==nums.size()){
        if(total==target) return 1;
        else return 0;
      }
      return calculate(nums,target,i+1,total+nums[i])+calculate(nums,target,i+1,total-nums[i]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {

      
      return calculate(nums,target,0,0);
        
    }
};