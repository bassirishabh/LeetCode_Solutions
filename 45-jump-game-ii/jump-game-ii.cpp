class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0;
        int right=0;
        int result=0;
        int maxsofar=0;

        while(right<nums.size()-1){
            for(int i=left;i<=right;i++){
                maxsofar=max(maxsofar,i+nums[i]);
            }
            result+=1;
            left=right;
            right=maxsofar;
        }
        return result;
    }
};