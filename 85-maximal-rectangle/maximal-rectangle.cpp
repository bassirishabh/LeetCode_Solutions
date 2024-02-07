class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);

        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            while((st.top()!=-1) && heights[st.top()]>=heights[i]){
                int currheight=heights[st.top()];
                                st.pop();
                int currwidth=i-st.top()-1;

                maxarea=max(maxarea,currheight*currwidth);
            }
            st.push(i);
        }
        while(st.top()!=-1){
            int curr=heights[st.top()];
                        st.pop();
            int width=n-st.top()-1;
            maxarea=max(maxarea,curr*width);

        }

        return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;

        int maxarea=0;
        vector<int> dp(matrix[0].size());

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                dp[j]=(matrix[i][j]=='1')?dp[j]+1:0;
            }
            maxarea=max(maxarea,largestRectangleArea(dp));
        }
        return maxarea;
        
    }
};