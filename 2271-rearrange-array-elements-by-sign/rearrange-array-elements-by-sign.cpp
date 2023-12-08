class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posindex=0;
        int negindex=1;
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++){
          if(nums[i]>0){
            result[posindex]=nums[i];
            posindex+=2;
          }else{
            result[negindex]=nums[i];
            negindex+=2;
          }
        }
        return result;
    }
};