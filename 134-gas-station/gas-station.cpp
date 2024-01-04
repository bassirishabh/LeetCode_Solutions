class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgain=0;
        int curgain=0;
        int ans=0;

        for(int i=0;i<gas.size();i++){
            totalgain+=(gas[i]-cost[i]);
            curgain+=(gas[i]-cost[i]);
            if(curgain<0){
                curgain=0;
                ans=i+1;
            }
        }
        return (totalgain>=0)?ans:-1;
    }
};