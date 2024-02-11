class Solution {
    public int rob(int[] nums) {
        int prev=nums[0];
        int prev2=0;
        int ans=0;
        for(int i=1;i<nums.length;i++){
            int nottake=prev;
            int take=prev2;
            take+=nums[i];
            ans=Math.max(take,nottake);
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
}