class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      int n=triplets.size();
      bool one=false,two=false,three=false;

      for(int i=0;i<n;i++){
        if(triplets[i][0]==target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) one=true;
        if(triplets[i][1]==target[1] && triplets[i][2]<=target[2] && triplets[i][0]<=target[0]) two=true;
        if(triplets[i][2]==target[2] && triplets[i][1]<=target[1] && triplets[i][0]<=target[0]) three=true;
      }
        return one && two && three;
    }
};