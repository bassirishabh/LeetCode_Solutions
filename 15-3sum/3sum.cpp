class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    vector<int> temp={nums[i],nums[left],nums[right]};
                    result.push_back(temp);
                    while(left<right && temp[1]==nums[left]) left++;
                    while(left<right && temp[2]==nums[right]) right--;
     
                }else if(sum<0) left++;
                else right--;
            }
        }
        return result;

    }
};