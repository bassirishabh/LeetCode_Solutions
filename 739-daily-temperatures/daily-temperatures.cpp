class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            int curr=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<curr){
                int prev=st.top();
                st.pop();
                result[prev]=(i-prev);
            }
            st.push(i);
        }
        return result;
    }
};