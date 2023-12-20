class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> umap;
        umap[')']='(';
        umap[']']='[';
        umap['}']='{';
        stack<int> st;
        for(auto i:s){
            if(umap.find(i)!=umap.end()){
                if(st.empty() || st.top()!=umap[i]){
                    return false;
                }
                st.pop();
            }

            else {
                st.push(i);
            }

        }
        return st.empty();
    }
};