class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,int sum, vector<int> temp,int index){
        if(sum==target){
            result.push_back(temp);
            return;
        }
        if(sum>target) return;

        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            backtrack(candidates,target,sum+candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,{},0);
        return result;
    }
};