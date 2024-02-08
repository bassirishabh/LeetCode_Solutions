class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0];
        int minsum=nums[0];
        int curmax=0;
        int curmin=0;
        int totalsum=0;
        for(int num:nums){
            curmax=max(curmax,0)+num;
            maxsum=max(maxsum,curmax);

            curmin=min(curmin,0)+num;
            minsum=min(minsum,curmin);

            totalsum+=num;
        }
        if(totalsum==minsum) return maxsum;

        return max(maxsum,totalsum-minsum);
    }
};