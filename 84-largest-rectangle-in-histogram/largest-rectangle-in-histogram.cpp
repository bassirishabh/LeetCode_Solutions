class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);

        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                int cur=heights[st.top()];
                st.pop();
                int width=i-st.top()-1;
                maxarea=max(maxarea,cur*width);
            }
            st.push(i);
        }
        while(st.top()!=-1){
            int cur=heights[st.top()];
            st.pop();
            int width=heights.size()-st.top()-1;
            maxarea=max(maxarea,cur*width);
        }
        return maxarea;
    }
};