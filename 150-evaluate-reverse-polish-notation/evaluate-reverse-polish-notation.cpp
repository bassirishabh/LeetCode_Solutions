class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto i:tokens){
            if(i=="+"){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.pop();
                st.push(s1+s2);
            }else if(i=="-"){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.pop();
                st.push(s2-s1);
            }
            else if(i=="*"){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.pop();
                st.push(s1*s2);
            }
            else if(i=="/"){
                int s1=st.top();
                st.pop();
                int s2=st.top();
                st.pop();
                st.push(s2/s1);
            }else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};