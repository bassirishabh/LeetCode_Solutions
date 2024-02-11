class Solution {
    public int rob1(ArrayList<Integer> nums) {
        int prev=nums.get(0);
        int prev2=0;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            int nottake=prev;
            int take=prev2;
            take+=nums.get(i);
            ans=Math.max(take,nottake);
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
    public int rob(int[] nums) {
        ArrayList<Integer> first=new ArrayList<>();
        ArrayList<Integer> last=new ArrayList<>();

        if(nums.length==1) return nums[0];
        for(int i=0;i<nums.length;i++){
            if(i>0) first.add(nums[i]);
            if(i!=nums.length-1) last.add(nums[i]);
        }
        return Math.max(rob1(first),rob1(last));
    }
}