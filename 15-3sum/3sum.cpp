class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    result.push_back(temp);
                    while(j<k && nums[j]==temp[1]) j++;
                    while(j<k && nums[k]==temp[2]) k--;

                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return result;
    }
};