class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curgain=0;
        int totalgain=0;
        int answer=0;
        for(int i=0;i<gas.size();i++){
            curgain+=(gas[i]-cost[i]);
            totalgain+=(gas[i]-cost[i]);
            if(curgain<0){
                curgain=0;
                answer=i+1;
            }
        }
        return (totalgain>=0)?answer:-1;
    }
};