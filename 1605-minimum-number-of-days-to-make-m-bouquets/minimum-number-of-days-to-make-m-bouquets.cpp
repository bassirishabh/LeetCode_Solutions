class Solution {
public:
    int possible(vector<int>& bloomDay, int k,int mid){
        int minbouq=0;
        int count=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                minbouq+=(count/k);
                count=0;
            }
        }
        minbouq+=(count/k);
        return minbouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,k,mid)>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};