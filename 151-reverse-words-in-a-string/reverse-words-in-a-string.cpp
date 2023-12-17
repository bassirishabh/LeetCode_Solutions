class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        for(int i=0;i<s.size();i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(word!="") st.push(word);
        }

        string result="";
        while(!st.empty()){
            result+=st.top()+" ";
            st.pop();
        }
        return result.substr(0,result.size()-1);
    }
};