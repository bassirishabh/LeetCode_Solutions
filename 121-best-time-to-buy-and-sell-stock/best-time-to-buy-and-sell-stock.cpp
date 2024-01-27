class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int profit=0;
        int maxprofit=0;
        int right=1;

        while(right<prices.size()){
            if(prices[left]<prices[right]){
                profit=prices[right]-prices[left];
                maxprofit=max(maxprofit,profit);
             
            }else{
                left=right;
            }
            right++;
        }
        return maxprofit;
    }
};