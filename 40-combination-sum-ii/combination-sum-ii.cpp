class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,int index,vector<int> curr){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1,curr);
            curr.pop_back();
        }
    }   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,{});
        return result;
    }
};