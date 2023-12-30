class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> result(n,0);

        for(int i=0;i<n;i++){
            int curtemp=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<curtemp){
                int prev=st.top();
                st.pop();
                result[prev]=(i-prev);
            }
            st.push(i);
        }
        return result;
    }
};