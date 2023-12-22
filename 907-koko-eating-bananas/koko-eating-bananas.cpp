class Solution {
public:
    long long findhours(vector<int> piles,int mid){
        long long ans=0;

        for(int i=0;i<piles.size();i++){
            ans+=ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxban=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        int low=1;
        int high=maxban;
        while(low<=high){
            int mid=(low+high)/2;
            if(findhours(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};