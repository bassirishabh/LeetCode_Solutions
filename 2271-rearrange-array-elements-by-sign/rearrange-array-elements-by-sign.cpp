class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size()/2;
        vector<int> neg;
        vector<int> pos;

        for(auto i:nums){
          if(i<0) neg.push_back(i);
          else pos.push_back(i);
        }
        int j=0;
        for(int i=0;i<n;i++){
          nums[j]=pos[i];
          nums[j+1]=neg[i];
          j+=2;
        }
        return nums;
    }
};