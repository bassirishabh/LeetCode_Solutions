class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxlength=0;
        for(auto i:nums) st.insert(i);

        for(auto i:nums){
            if(st.find(i-1)==st.end()){
                int length=0;
                while(st.find(i+length)!=st.end()){
                    length++;
                }
                maxlength=max(length,maxlength);
            }
        }
        return maxlength;
    }
};