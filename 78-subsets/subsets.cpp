class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int index,vector<int> temp){
        result.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums,0,temp);
        return result;
    }
};