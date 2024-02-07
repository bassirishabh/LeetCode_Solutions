class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto as:asteroids){
            int flag = 1;
            while(!st.empty() && (st.top()>0 && as<0)){
                if(abs(st.top())<abs(as)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(as)){
                    st.pop();   
                }
                flag=0;
                break;
            }
            if(flag) st.push(as);
        }
        vector<int> rem;
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        reverse(rem.begin(),rem.end());
        return rem;
    }
};