class Solution {
public:
    void reverse(vector<int>& nums,int left,int right){
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(nums.size()<k) return;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
        
    }
};