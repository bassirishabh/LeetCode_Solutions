class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result="";
        for(auto i:strs){
            int len=i.size();
            result+=to_string(len)+"#"+i;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.size()){
            int delim=s.find("#",i);
            int length=stoi(s.substr(i,delim-i));
            string temp="";
            temp=s.substr(delim+1,length);
            result.push_back(temp);
            i=delim+1+length;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));