class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=nums.size();
        int xor2=0;
        for(int i=0;i<nums.size();i++){
          xor1^=i;
          xor2^=nums[i];
        }
        return xor1^xor2;
    }
};