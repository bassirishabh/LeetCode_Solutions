class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> umap;
        for(auto i : hand) umap[i]++;

        sort(hand.begin(),hand.end());

        for(int i=0;i<hand.size();i++){
          if(umap[hand[i]]==0) continue;
          for(int j=0;j<groupSize;j++){
            int cur=hand[i]+j;
            if(umap[cur]==0) return false;
            umap[cur]--;
          }
        }
        return true;
    }
};