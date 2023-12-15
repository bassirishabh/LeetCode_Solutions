class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        while(i<s.size()){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            
            if(word!="") st.push(word);
            i++;
        }
        string s1="";
        while(!st.empty()){
            s1+=st.top()+" ";
            st.pop();
        }
        return s1.substr(0,s1.size()-1);
    }
};