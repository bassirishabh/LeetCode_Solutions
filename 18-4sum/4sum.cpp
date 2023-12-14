class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;


        for(int i=0;i<n;i++){
            for(int b=i+1;b<n;b++){
                int left=b+1;
                int right=n-1;
                while(left<right){
                    long long sum=(long long)nums[i]+(long long)nums[b]+(long long)nums[left]+(long long)nums[right];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[b],nums[left],nums[right]};
                        st.insert(temp);
                        left++;
                        right--;
                    }else if(sum<target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
};