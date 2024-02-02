class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto i:nums) st.insert(i);

        int i=0;
        int maxlen=0;
        while(i<nums.size()){
            if(st.find(nums[i]-1)==st.end()){
                int length=1;
                while(st.find(nums[i]+length)!=st.end()){
                    length++;
                }
                maxlen=max(maxlen,length);
            }
            i++;
        }
        return maxlen;
    }
};