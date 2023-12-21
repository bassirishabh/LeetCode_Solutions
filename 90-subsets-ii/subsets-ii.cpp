class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums,int index,vector<int> temp){
        result.push_back(temp);

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0,{});
        return result;
    }
};