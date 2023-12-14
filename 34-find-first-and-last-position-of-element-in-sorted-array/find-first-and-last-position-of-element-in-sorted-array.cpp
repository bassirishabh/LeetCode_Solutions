class Solution {
public:
    int lowerbound1(vector<int>&nums, int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int upperbound1(vector<int>&nums, int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerbound=lowerbound1(nums,target);
        int upperbound=upperbound1(nums,target);
        return {lowerbound,upperbound};
    }
};