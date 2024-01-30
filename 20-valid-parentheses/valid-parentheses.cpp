class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> umap;
        umap['}']='{';
        umap[')']='(';
        umap[']']='[';
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(umap.find(s[i])!=umap.end()){
                if(st.empty()) return false;
                if(st.top()!=umap[s[i]]) return false;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};