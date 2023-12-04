class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto i:stones) pq.push(i);
        

        while(pq.size()>1){
            int topmost=pq.top();
            pq.pop();
            int secondmost=pq.top();
            pq.pop();
            if(topmost==secondmost) continue;
            else pq.push(topmost-secondmost);
        }
        if(pq.size()==1) return pq.top();
        else return 0;
    }
};