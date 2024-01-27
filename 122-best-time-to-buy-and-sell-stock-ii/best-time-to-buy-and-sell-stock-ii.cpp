class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int left=0;
        int right=1;
        while(right<prices.size()){
            if(prices[right]>prices[left]){
                profit+=prices[right]-prices[left];
            }
            left++;
            right++; 
            
        }
        return profit;
    }
};