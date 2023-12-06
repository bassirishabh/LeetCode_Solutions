class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        priority_queue<int,vector<int>,greater<int>> minheap;

        minheap.push(intervals[0][1]);

        for(int i=1;i<intervals.size();i++){
          if(intervals[i][0]>=minheap.top()){
            minheap.pop();
          }
          minheap.push(intervals[i][1]);
        }
        return minheap.size();
    }
};