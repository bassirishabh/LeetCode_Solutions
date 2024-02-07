class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,vector<int> temp,int index){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],temp,i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,{},0);
        return result;
    }
};