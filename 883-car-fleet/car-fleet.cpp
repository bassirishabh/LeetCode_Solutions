class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> ps;

        for(int i=0;i<n;i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end());

        vector<float> time(n);
        for(int i=0;i<n;i++){
            time[i]=(float)(target-ps[i].first)/ps[i].second;
        }

        int fleets=n;
        for(int i=n-1;i>0;i--){
            if(time[i]>=time[i-1]){
                time[i-1]=time[i];
                fleets--;
            }
        }
        return fleets;
    }
};