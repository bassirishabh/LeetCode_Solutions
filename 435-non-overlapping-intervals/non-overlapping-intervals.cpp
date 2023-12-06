
bool cmp(vector<int> a,vector<int> b){
  return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int count=0;
        int min=INT_MIN;
        for(int i=0;i<intervals.size();i++){
          if(intervals[i][0]>=min) min=intervals[i][1];
          else count++;
        }
        return count;
    }
};