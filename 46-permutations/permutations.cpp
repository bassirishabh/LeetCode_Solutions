class Solution {
public:
    vector<vector<int>>  result;

    void backtrack(vector<int>& nums,vector<int> curr){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }
        for(int num:nums){
            if(find(curr.begin(),curr.end(),num)==curr.end()){
                curr.push_back(num);
                backtrack(nums,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,{});
        return result;
    }
};