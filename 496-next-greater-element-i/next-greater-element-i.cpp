class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> umap;

        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>st.top()){
                umap[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            umap[st.top()]=-1;
            st.pop();
        }
        vector<int> res;

        for(int i=0;i<nums1.size();i++){
            res.push_back(umap[nums1[i]]);
        }
        return res;
    }
};