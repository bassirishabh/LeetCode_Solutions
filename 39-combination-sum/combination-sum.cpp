class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,int sum,int index,vector<int> temp){
        if(target==sum){
            result.push_back(temp);
            return;
        }
        if(sum>target) return;
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            backtrack(candidates,target,sum+candidates[i],i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0,0,{});
        return result;
    }
};